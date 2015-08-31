#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H
#define PEDIDO 1
#define ENTREGA 2
#define PG_CARTAO 3
#define PG_DINHEIRO 4

class Distribution
{
    public:
        Distribution();
        virtual ~Distribution();
        double uniform_distribution(int type);
        double triangular_distribution(int type);
        double generate_random();
    protected:
    private:
};

#endif // DISTRIBUTION_H
