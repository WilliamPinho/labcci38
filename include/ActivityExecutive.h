#ifndef ACTIVITYEXECUTIVE_H
#define ACTIVITYEXECUTIVE_H
#define CHEGADA 5
#include "Activity.h"
#include <deque>
using namespace std;

class ActivityExecutive
{
    public:
        bool atend_pedido_livre;
        bool atend_entrega_livre;
        bool atend_cartao_livre;
        bool atend_dinheiro_livre;
        deque<Entity> filaPedido;
        deque<Entity> filaEntrega;
        deque<Entity> filaCartao;
        deque<Entity> filaDinheiro;
        ActivityExecutive();
        ActivityExecutive(double sim_end);
        virtual ~ActivityExecutive();
        double simulationTime();
        double simulationEnd();
        Activity *getActivity();
        double timeScan();
        double getActivityTime();
        void addActivity(double time, int activity, Entity entity);
        void removeActivity();
        void executeActivities();
    protected:
        deque<Activity *> activity_list;
        double simulation_time;
        double simulation_end;
    private:
};

#endif // ACTIVITYEXECUTIVE_H
