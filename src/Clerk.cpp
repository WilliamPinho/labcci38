#include "Clerk.h"
#include "ActivityExecutive.h"
#include <iostream>
#define CHEGADA         5
#define COMECO_PEDIDO   6
#define FIM_PEDIDO      7
#define COMECO_ENTREGA  8
#define FIM_ENTREGA     9
#define COMECO_CARTAO   10
#define FIM_CARTAO      11
#define COMECO_DINHEIRO 12
#define FIM_DINHEIRO    13

Clerk::Clerk()
{
}

Clerk::~Clerk()
{
    //dtor
}

void Clerk::chegadaCliente()
{
    double time1;
    double sim_time = this->executive->simulationTime();
    if(this->activity == CHEGADA && time == sim_time)
    {
        Entity client;
        time1 = sim_time + 1;
        this->executive->addActivity(time1, CHEGADA, client);
        cout << sim_time << ": chega cliente ";
        int rand = this->distribution.generate_random();
        if(rand <= 25)
        {
            cout << "que vai para a fila de entrega." << endl << endl;
            this->executive->filaEntrega.push_back(client);
        }
        else
        {
            cout << "que vai para a fila de pedidos." << endl << endl;
            this->executive->filaPedido.push_back(client);
        }
    }
}

void Clerk::comecoPedido()
{
    double time1;
    double sim_time = this->executive->simulationTime();
    if(this->executive->atend_pedido_livre)
    {
        if(!this->executive->filaPedido.empty())
        {
            cout << sim_time << ": cliente comeca a fazer pedido." << endl << endl;
            Entity client = this->executive->filaPedido.front();
            client.setActivity(COMECO_PEDIDO);
            this->executive->filaPedido.pop_front();
            time1 = sim_time + this->distribution.triangular_distribution(PEDIDO);
            this->executive->addActivity(time1, FIM_PEDIDO, client);
            this->executive->atend_pedido_livre = false;
        }
    }
}

void Clerk::fimPedido()
{
    double sim_time = this->executive->simulationTime();
    if(activity == FIM_PEDIDO && time == sim_time)
    {
        cout << sim_time << ": cliente termina pedido e vai para fila de entregas." << endl << endl;
        this->executive->atend_pedido_livre = true;
        Entity client;
        this->executive->filaEntrega.push_back(client);
    }
}

void Clerk::comecoEntrega()
{
    double time1;
    double sim_time = this->executive->simulationTime();
    if(this->executive->atend_entrega_livre)
    {
        if(!this->executive->filaEntrega.empty())
        {
            cout << sim_time << ": cliente comeca a receber entrega." << endl << endl;
            Entity client = this->executive->filaEntrega.front();
            client.setActivity(COMECO_ENTREGA);
            this->executive->filaEntrega.pop_front();
            time1 = sim_time + this->distribution.triangular_distribution(ENTREGA);
            this->executive->addActivity(time1, FIM_ENTREGA, client);
            this->executive->atend_entrega_livre = false;
        }
    }
}

void Clerk::fimEntrega()
{
    double sim_time = this->executive->simulationTime();
    if(this->activity == FIM_ENTREGA && time == sim_time)
    {
        cout << sim_time << ": cliente termina de receber entrega";
        this->executive->atend_entrega_livre = true;
        Entity client;
        int rand = this->distribution.generate_random();
        if(rand <= 10)
        {
            cout << " e vai para fila de pagamento em dinheiro." << endl << endl;
            this->executive->filaDinheiro.push_back(client);
        }
        else
        {
            cout << " e vai para fila de pagamento em cartao." << endl << endl;
            this->executive->filaCartao.push_back(client);
        }
    }
}

void Clerk::comecoPagamentoCartao()
{
    double time1;
    double sim_time = this->executive->simulationTime();
    if(this->executive->atend_cartao_livre)
    {
        if(!this->executive->filaCartao.empty())
        {
            cout << sim_time << ": cliente comeca a pagar com cartao." << endl << endl;
            Entity client = this->executive->filaCartao.front();
            client.setActivity(COMECO_CARTAO);
            this->executive->filaCartao.pop_front();
            time1 = sim_time + this->distribution.uniform_distribution(PG_CARTAO);
            this->executive->addActivity(time1, FIM_CARTAO, client);
            this->executive->atend_cartao_livre = false;
        }
    }
}

void Clerk::fimPagamentoCartao()
{
    double sim_time = this->executive->simulationTime();
    if(this->activity == FIM_CARTAO && time == sim_time)
    {
        cout << sim_time << ": cliente termina de pagar com cartao." << endl << endl;
        this->executive->atend_cartao_livre = true;
    }
}

void Clerk::comecoPagamentoDinheiro()
{
    double time1;
    double sim_time = this->executive->simulationTime();
    if(this->executive->atend_dinheiro_livre)
    {
        if(!this->executive->filaDinheiro.empty())
        {
            cout << sim_time << ": cliente comeca a pagar com dinheiro." << endl << endl;
            Entity client = this->executive->filaDinheiro.front();
            client.setActivity(COMECO_DINHEIRO);
            this->executive->filaDinheiro.pop_front();
            time1 = sim_time + this->distribution.uniform_distribution(PG_DINHEIRO);
            this->executive->addActivity(time1, FIM_DINHEIRO, client);
            this->executive->atend_dinheiro_livre = false;
        }
    }
}

void Clerk::fimPagamentoDinheiro()
{
    double sim_time = this->executive->simulationTime();
    if(this->activity == FIM_DINHEIRO && time == sim_time)
    {
        cout << sim_time << ": cliente termina de pagar com dinheiro." << endl << endl;
        this->executive->atend_dinheiro_livre = true;
    }
}

void Clerk::executarAtividade()
{
    this->chegadaCliente();
    this->comecoPedido();
    this->fimPedido();
    this->comecoEntrega();
    this->fimEntrega();
    this->comecoPagamentoCartao();
    this->fimPagamentoCartao();
    this->comecoPagamentoDinheiro();
    this->fimPagamentoDinheiro();
}
