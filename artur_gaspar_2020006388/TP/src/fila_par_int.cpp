//---------------------------------------------------------------------
// Arquivo      : fila_par_int.cpp
// Conteudo     : arquivo de implementação para fila de par de inteiros.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "fila_par_int.hpp"
#include "msgassert.hpp"
#include <stdlib.h>

Fila_Par_Int::Fila_Par_Int(int capacidade)
{
    this->capacidade = ++capacidade;
    this->quantidade = 0;
    this->primeiro = new int[capacidade];
    this->pos_init = 0;
    this->pos_final = 0;
    this->segundo = new int[capacidade];
}

void Fila_Par_Int::adiciona(int a, int b)
{
    erroAssert(this->quantidade < this->capacidade, "Fila cheia, nao eh possivel adicionar mais elementos.");

    int n = this->capacidade;
    this->primeiro[this->pos_final] = a;
    this->segundo [this->pos_final] = b;
    this->quantidade++;
    this->pos_final = (this->pos_final + 1) % n;
}

int Fila_Par_Int::primeiro_a()
{
    return this->primeiro[this->pos_init];
}

int Fila_Par_Int::primeiro_b()
{
    return this->segundo[this->pos_init];
}

void Fila_Par_Int::tira_primeiro()
{
    erroAssert(this->quantidade > 0, "Fila vazia, nao eh possivel remover elementos.");
    int n = this->capacidade;
    this->pos_init = (this->pos_init + 1 + n) % n;
    this->quantidade--;
}

bool Fila_Par_Int::vazia()
{
    return this->quantidade == 0;
}

void Fila_Par_Int::destruir()
{
    if (this->capacidade == 0)
        return;
    delete[] this->primeiro;
    delete[] this->segundo;
    this->quantidade = 0;
    this->capacidade = 0;
    this->pos_init = 0;
    this->pos_final = 1;
}

Fila_Par_Int::~Fila_Par_Int()
{
    this->destruir();
}