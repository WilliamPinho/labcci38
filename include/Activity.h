#ifndef ACTIVITY_H
#define ACTIVITY_H
#include "Entity.h"

class ActivityExecutive;

class Activity
{
    public:
        Activity();
        Activity(double time, int activity, Entity entity, ActivityExecutive *e);
        virtual ~Activity();
        void setActivity(double time, int activity, Entity entity);
        double getTime();
        int getActivity();
        Entity getEntity();
        void executarAtividade();
    protected:
        double time;
        int activity;
        Entity entity;
        ActivityExecutive *executive;
    private:
};

#endif // ACTIVITY_H
