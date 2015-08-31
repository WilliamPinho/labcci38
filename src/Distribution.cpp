#include "Distribution.h"
#include <iostream>
#include <chrono>
#include <random>
#include <boost/random.hpp>

using namespace std;

Distribution::Distribution()
{
    //ctor
}

Distribution::~Distribution()
{
    //dtor
}

double Distribution::uniform_distribution(int type)
{
    if(type != PG_CARTAO && type != PG_DINHEIRO) return -1.0;

    double min_value = type == PG_CARTAO ? 0.5 : 0.2;
    double max_value = type == PG_CARTAO ? 1.5 : 1.0;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    uniform_real_distribution<double> distribution (min_value,max_value);

    return distribution(generator);
}

double Distribution::triangular_distribution(int type)
{
    if(type != PEDIDO && type != ENTREGA) return -1.0;

    double lower = type == PEDIDO ? 0.05 : 0.5;
    double mode = type == PEDIDO ? 0.5 : 1;
    double upper = type == PEDIDO ? 1.0 : 2;

    boost::lagged_fibonacci607 rng;

    rng.seed(static_cast<boost::uint32_t>(std::time(0)));

    boost::triangle_distribution<> myTriangular(lower, mode, upper);

    boost::variate_generator<boost::lagged_fibonacci607&, boost::triangle_distribution<>> triRng(rng, myTriangular);

    return triRng();
}

double Distribution::generate_random()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_int_distribution<int> distribution(1,100);
    return distribution(generator);
}


