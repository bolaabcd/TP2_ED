//---------------------------------------------------------------------
// Arquivo      : pilha_par_int.cpp
// Conteudo     : arquivo de implementação para pilha de par de inteiros.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "pilha_par_int.hpp"
#include <stdlib.h>
#include "msgassert.hpp"

Pilha_Par_Int::Pilha_Par_Int(int capacidade_inicial)
// Descricao: construtor de pilha de par de inteiros que implementam heapsort
// recursivo.
// Entrada: capacidade inicial da pilha (muda durante a execucao se necessario).
// Saida: instância do tipo Pilha_Par_Int.
{
    erroAssert(capacidade_inicial >= 0, "Nao eh permitido pilha de capacidade negativa");
    this->capacidade = capacidade_inicial;
    this->quantidade = 0;
    this->primeiro = (int *)malloc(capacidade_inicial * sizeof(int));
    this->segundo = (int *)malloc(capacidade_inicial * sizeof(int));
}

void Pilha_Par_Int::adiciona(int a, int b)
// Descricao: adiciona par de inteiros a pilha.
// Entrada: valores do par a adicionar.
// Saida: altera os arrays this->primeiro e this->segundo.
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
// Descricao: informa o primeiro inteiro do primeiro elemento da pilha.
// Entrada: nao tem.
// Saida: primeiro inteiro do primeiro elemento da pilha.
{
    erroAssert(!this->vazia(), "Pilha vazia, nao eh possivel obter primeiro elemento");

    return this->primeiro[this->quantidade - 1];
}

int Pilha_Par_Int::topo_b()
// Descricao: informa o segundo inteiro do primeiro elemento da pilha.
// Entrada: nao tem.
// Saida: segundo inteiro do primeiro elemento da pilha.
{
    erroAssert(!this->vazia(), "Pilha vazia, nao eh possivel obter primeiro elemento");

    return this->segundo[this->quantidade - 1];
}

void Pilha_Par_Int::tira_topo()
// Descricao: tira o primeiro elemento da pilha.
// Entrada: nao tem.
// Saida: nao tem.
{
    erroAssert(!this->vazia(), "Pilha vazia, nao eh possivel tirar primeiro elemento");

    this->quantidade--;
}

bool Pilha_Par_Int::vazia()
// Descricao: informa se a pilha esta vazia.
// Entrada: nao tem.
// Saida: verdadeiro se esta vazia, falso caso contrario.
{
    return this->quantidade == 0;
}

void Pilha_Par_Int::destruir()
// Descricao: destroi a pilha.
// Entrada: nao tem.
// Saida: nao tem.
{
    if (this->capacidade == 0)
        return;
    delete[] this->primeiro;
    delete[] this->segundo;
    this->quantidade = 0;
    this->capacidade = 0;
}

Pilha_Par_Int::~Pilha_Par_Int()
// Descricao: destruidor padrao da pilha.
// Entrada: nao tem.
// Saida: nao tem.
{
    this->destruir();
}