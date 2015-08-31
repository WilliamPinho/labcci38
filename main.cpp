#include <iostream>
#include "ActivityExecutive.h"

using namespace std;

int main()
{
    double sim_end;
    cout << "--- Simulacao ---" << endl;
    cout << "Insira o tempo de simulacao: ";
    cin >> sim_end;
    cout << endl;
    ActivityExecutive executive(sim_end);
    Entity client;
    client.setActivity(CHEGADA);
    executive.addActivity(0,CHEGADA, client);

    while(executive.simulationTime() < executive.simulationEnd())
    {
        executive.timeScan();
        executive.executeActivities();
    }
    return 0;
}
