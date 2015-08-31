#include "ActivityExecutive.h"
#include "Clerk.h"
#include <deque>
#include <iostream>
#include <algorithm>

bool compare_activities (Activity* first, Activity* second)
{
  return first->getTime() <= second->getTime();
}

ActivityExecutive::ActivityExecutive()
{
    this->simulation_time = 0.0;
    this->simulation_end = 0.0;
    this->atend_cartao_livre = true;
    this->atend_dinheiro_livre = true;
    this->atend_entrega_livre = true;
    this->atend_pedido_livre = true;
}

ActivityExecutive::ActivityExecutive(double sim_end)
{
    this->simulation_time = 0.0;
    this->simulation_end = sim_end;
    this->atend_cartao_livre = true;
    this->atend_dinheiro_livre = true;
    this->atend_entrega_livre = true;
    this->atend_pedido_livre = true;
}

ActivityExecutive::~ActivityExecutive()
{
    //dtor
}

double ActivityExecutive::simulationTime()
{
    return this->simulation_time;
}

double ActivityExecutive::simulationEnd()
{
    return this->simulation_end;
}

Activity *ActivityExecutive::getActivity()
{
    return this->activity_list.front();
}

double ActivityExecutive::timeScan()
{
    this->simulation_time = this->getActivity()->getTime();
    return this->simulation_time;
}

double ActivityExecutive::getActivityTime()
{
    return this->getActivity()->getTime();
}

void ActivityExecutive::addActivity(double time, int activity, Entity entity)
{
    Activity * activ = new Activity(time, activity, entity, this);

    this->activity_list.push_back(activ);
    sort(this->activity_list.begin(), this->activity_list.end(), compare_activities);
}

void ActivityExecutive::removeActivity()
{
    delete this->activity_list.front();
    this->activity_list.pop_front();
}

void ActivityExecutive::executeActivities()
{
    Clerk *activ;
    double sim_time = this->simulationTime();
    while(sim_time == this->getActivityTime())
    {
        activ = static_cast<Clerk *> (this->getActivity());
        activ->executarAtividade();
        this->removeActivity();
    }
}
