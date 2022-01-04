//---------------------------------------------------------------------
// Arquivo      : pilha_par_int.cpp
// Conteudo     : arquivo de implementação para pilha de par de inteiros.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "pilha_par_int.hpp"
#include  <stdlib.h>

Pilha_Par_Int::Pilha_Par_Int(int capacidade_inicial)
{
    this->capacidade = capacidade_inicial;
    this->quantidade = 0;
    this->primeiro = new int[capacidade_inicial];
    this->segundo = new int[capacidade_inicial];
}

void Pilha_Par_Int::adiciona(int a, int b)
{
    if (this->capacidade < this->quantidade + 1)
    {
        this->capacidade = 2 * this->capacidade;
        this->primeiro = (int *)realloc(this->primeiro, this->capacidade * sizeof(int));
        this->segundo = (int *)realloc(this->segundo, this->capacidade * sizeof(int));
    }
    this->primeiro[this->quantidade] = a;
    this->segundo[this->quantidade++] = b;
}

int Pilha_Par_Int::topo_a()
{
    return this->primeiro[this->quantidade - 1];
}

int Pilha_Par_Int::topo_b()
{
    return this->segundo[this->quantidade - 1];
}

void Pilha_Par_Int::tira_topo()
{
    this->quantidade--;
}

bool Pilha_Par_Int::vazia() {
    return this->quantidade==0;
}

void Pilha_Par_Int::destruir(){
    if(this->capacidade == 0)
        return;
    delete[] this->primeiro;
    delete[] this->segundo;
    this->quantidade = 0;
    this->capacidade = 0;
}

Pilha_Par_Int::~Pilha_Par_Int(){
    this->destruir();
}