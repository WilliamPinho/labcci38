#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
        Entity();
        virtual ~Entity();
        int getActivity();
        void setActivity(int activity);
        double getArrive();
        void setArrive(double arrive);
        double getStart();
        void setStart(double start);
        double getEnd();
        void setEnd(double end_);
    protected:
        int activity;
        double arrive;
        double start;
        double end_;
    private:
};

#endif // ENTITY_H
