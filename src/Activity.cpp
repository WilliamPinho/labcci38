#include "Activity.h"

Activity::Activity()
{
    //ctor
}

Activity::~Activity()
{
    //dtor
}

Activity::Activity(double time, int activity, Entity entity, ActivityExecutive *e)
{
    this->executive = e;
    this->time = time;
    this->activity = activity;
    this->entity = entity;
}

void Activity::setActivity(double time, int activity, Entity entity)
{
    this->time = time;
    this->activity = activity;
    this->entity = entity;
}

double Activity::getTime()
{
    return this->time;
}

int Activity::getActivity()
{
    return this->activity;
}

Entity Activity::getEntity()
{
    return this->entity;
}


