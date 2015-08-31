#ifndef CLERK_H
#define CLERK_H
#include "Entity.h"
#include "Distribution.h"
#include "Activity.h"
#include <deque>

using namespace std;

class Clerk : public Activity
{
    public:
        Distribution distribution;
        Clerk();
        virtual ~Clerk();
        void chegadaCliente();
        void comecoPedido();
        void fimPedido();
        void comecoEntrega();
        void fimEntrega();
        void comecoPagamentoCartao();
        void fimPagamentoCartao();
        void comecoPagamentoDinheiro();
        void fimPagamentoDinheiro();
        void executarAtividade();
    protected:
    private:
};

#endif // CLERK_H
