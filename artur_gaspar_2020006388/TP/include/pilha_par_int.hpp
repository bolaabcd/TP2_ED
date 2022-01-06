//---------------------------------------------------------------------
// Arquivo      : pilha_par_int.hpp
// Conteudo     : arquivo de cabeçalho para pilha de par de inteiros.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef PILHA_DE_PAR_DE_INTEIROS
#define PILHA_DE_PAR_DE_INTEIROS

class Pilha_Par_Int
{
public:
    Pilha_Par_Int(int capacidade_inicial);
    void adiciona(int a, int b);
    int topo_a();
    int topo_b();
    void tira_topo();
    bool vazia();
    void destruir();
    ~Pilha_Par_Int();

private:
    int capacidade;
    int quantidade;
    int *primeiro;
    int *segundo;
};

#endif