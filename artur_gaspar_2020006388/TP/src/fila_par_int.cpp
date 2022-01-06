//---------------------------------------------------------------------
// Arquivo      : fila_par_int.cpp
// Conteudo     : arquivo de implementacao para fila de par de inteiros.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "fila_par_int.hpp"
#include "msgassert.hpp"
#include <stdlib.h>

Fila_Par_Int::Fila_Par_Int(int capacidade)
// Descricao: construtor da fila de par de inteiros.
// Entrada: capacidade da fila (nao muda durante a execucao do programa).
// Saida: instância de fila de par de inteiros.
{
    erroAssert(capacidade >= 0, "Nao eh permitido fila de capacidade negativa");
    this->capacidade = ++capacidade;
    this->quantidade = 0;
    this->primeiro = new int[capacidade];
    this->pos_init = 0;
    this->pos_final = 0;
    this->segundo = new int[capacidade];
}

void Fila_Par_Int::adiciona(int a, int b)
// Descricao: adiciona par de inteiros a fila.
// Entrada: os dois inteiros a adicionar.
// Saida: nao tem.
{
    erroAssert(this->quantidade < this->capacidade, "Fila cheia, nao eh possivel adicionar mais elementos.");

    int n = this->capacidade;
    this->primeiro[this->pos_final] = a;
    this->segundo[this->pos_final] = b;
    this->quantidade++;
    this->pos_final = (this->pos_final + 1) % n;
}

int Fila_Par_Int::primeiro_a()
// Descricao: retorna o primeiro inteiro do primeiro elemento da fila.
// Entrada: nao tem.
// Saida: primeiro inteiro do primeiro elemento da fila.
{
    erroAssert(!this->vazia(), "Fila vazia, nao eh possivel obter primeiro elemento");
    return this->primeiro[this->pos_init];
}

int Fila_Par_Int::primeiro_b()
// Descricao: retorna o segundo inteiro do primeiro elemento da fila.
// Entrada: nao tem.
// Saida: primeiro inteiro do primeiro elemento da fila.
{
    erroAssert(!this->vazia(), "Fila vazia, nao eh possivel obter primeiro elemento");
    return this->segundo[this->pos_init];
}

void Fila_Par_Int::tira_primeiro()
// Descricao: tira o primeiro elemento da fila.
// Entrada: nao tem.
// Saida: nao tem.
{
    erroAssert(!this->vazia(), "Fila vazia, nao eh possivel remover elementos.");
    int n = this->capacidade;
    this->pos_init = (this->pos_init + 1 + n) % n;
    this->quantidade--;
}

bool Fila_Par_Int::vazia()
// Descricao: informa se a fila esta vazia.
// Entrada: nao tem.
// Saida: verdadeiro se a fila esta vazia, falso caso contrario.
{
    return this->quantidade == 0;
}

void Fila_Par_Int::destruir()
// Descricao: desroi fila de par de inteiros.
// Entrada: nao tem.
// Saida: nao tem.
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
// Descricao: destrutor padrao pra fila de par de inteiros.
// Entrada: nao tem.
// Saida: nao tem.
{
    this->destruir();
}