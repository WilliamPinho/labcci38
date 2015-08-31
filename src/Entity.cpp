#include "Entity.h"

Entity::Entity()
{
    //ctor
}

Entity::~Entity()
{
    //dtor
}

int Entity::getActivity()
{
    return this->activity;
}

void Entity::setActivity(int activity)
{
    this->activity = activity;
}

double Entity::getArrive()
{
    return this->arrive;
}

void Entity::setArrive(double arrive)
{
    this->arrive = arrive;
}

double Entity::getStart()
{
    return this->start;
}

void Entity::setStart(double start)
{
    this->start = start;
}

double Entity::getEnd()
{
    return this->end_;
}

void Entity::setEnd(double end_)
{
    this->end_ = end_;
}
