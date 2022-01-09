//---------------------------------------------------------------------
// Arquivo      : heap_url_acessos.cpp
// Conteudo     : arquivo de implementação para heap de url_acessoss.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "heap_url_acessos.hpp"
#include "url_acessos.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

Heap_URL_Acessos::Heap_URL_Acessos(int num_elementos)
// Descricao: construtor de heap de elementos URL_Acessos.
// Entrada: numero de elementos que podem ser colocados no heap (constante
// durante a execucao do programa).
// Saida: instância de Heap de URL_Acessos.
{
    erroAssert(num_elementos >= 0, "Nao eh permitido heap de capacidade negativa");
    this->capacidade = num_elementos;
    this->quantidade = 0;
    this->heap = new URL_Acessos[num_elementos + 1];
    this->rodadas = new int[num_elementos + 1];
}

void Heap_URL_Acessos::adicionar(URL_Acessos url_acessos, int rodada)
// Descricao: adiciona elemento ao heap.
// Entrada: URL_Acessos a ser adicionada e sua rodada correspondente.
// Saida: nao tem.
{
    erroAssert(rodada >= 0, "A rodada nao pode ser um valor negativo.");

    this->rodadas[++this->quantidade] = rodada;
    escreveMemLog((long int)&this->heap[this->quantidade], sizeof(URL_Acessos), 0);
    this->heap[this->quantidade] = url_acessos;

    for (int i = this->quantidade / 2; i > 0; i /= 2)
        refaz(i, this->quantidade);
}

URL_Acessos Heap_URL_Acessos::url_acessos_primeiro()
// Descricao: informa o primeiro URL_Acesos.
// Entrada: nao tem.
// Saida: primeiro elemento do heap.
{
    erroAssert(!this->vazio(), "Nao eh possivel obter o primeiro elemento de um heap vazio");
    leMemLog((long int)&this->heap[1], sizeof(URL_Acessos), 0);
    return this->heap[1];
}

int Heap_URL_Acessos::rodada_primeiro()
// Descricao: informa a rodada do primeiro URL_Acessos.
// Entrada: nao tem.
// Saida: rodada do primeiro elemento do heap.
{
    erroAssert(!this->vazio(), "Nao eh possivel obter o primeiro elemento de um heap vazio");
    return this->rodadas[1];
}

void Heap_URL_Acessos::tira_primeiro()
// Descricao: remove o primeiro elemento do heap (tanto o URL_Acessos quanto
// sua rodada).
// Entrada: nao tem.
// Saida: nao tem.
{
    erroAssert(!this->vazio(), "Nao eh possivel tirar o primeiro elemento de um heap vazio");
    this->heap[1] = heap[this->quantidade];
    escreveMemLog((long int)&this->heap[1], sizeof(URL_Acessos), 0);
    leMemLog((long int)&this->heap[this->quantidade], sizeof(URL_Acessos), 0);
    this->rodadas[1] = rodadas[this->quantidade--];

    if (this->quantidade == 0)
        return;
    refaz(1, this->quantidade);
}

bool Heap_URL_Acessos::vazio()
// Descricao: informa se o heap esta vazio.
// Entrada: nao tem.
// Saida: verdadeiro se o heap esta vazio, falso caso contrario.
{
    return this->quantidade == 0;
}

Heap_URL_Acessos::~Heap_URL_Acessos()
// Descricao: destrutor padrao do Heap_URL_Acessos().
// Entrada: nao tem.
// Saida: nao tem.
{
    if (this->capacidade <= 0)
        return;
    this->capacidade = 0;
    this->quantidade = 0;
    delete[] this->heap;
    delete[] this->rodadas;
}

void Heap_URL_Acessos::refaz(int l, int tam)
// Descricao: funcao auxiliar que arruma um galho do heap a partir de l.
// Entrada: posicao inicial a refazer e tamanho total do heap.
// Saida: altera o this->heap e o this->rodadas.
{
    erroAssert(l >= 1 && l <= tam, "Valores invalidos para o algoritmo de heap.");
    int pai = l;
    URL_Acessos filhoR, filhoL;
    int maior = 2 * l;

    if (2 * l + 1 <= tam)
    {
        filhoL = this->heap[2 * l + 1];
        filhoR = this->heap[2 * l];
        leMemLog((long int)&this->heap[2 * l + 1], sizeof(URL_Acessos), 1);
        leMemLog((long int)&this->heap[2 * l], sizeof(URL_Acessos), 1);
        if (filhoR < filhoL)
        {
            maior = 2 * l + 1;
        }
    }
    else if (2 * l <= tam)
    {
        filhoR = this->heap[2 * l];
        leMemLog((long int)&this->heap[2 * l], sizeof(URL_Acessos), 1);
    }
    else
    {
        return;
    }

    if (this->heap[pai] < this->heap[maior])
    {
        leMemLog((long int)&this->heap[pai], sizeof(URL_Acessos), 1);
        leMemLog((long int)&this->heap[maior], sizeof(URL_Acessos), 1);
        // Trocando elementos
        URL_Acessos url_pai = this->heap[pai];
        leMemLog((long int)&this->heap[pai], sizeof(URL_Acessos), 0);
        this->heap[pai] = this->heap[maior];
        leMemLog((long int)&this->heap[maior], sizeof(URL_Acessos), 0);
        escreveMemLog((long int)&this->heap[pai], sizeof(URL_Acessos), 0);
        this->heap[maior] = url_pai;
        escreveMemLog((long int)&this->heap[maior], sizeof(URL_Acessos), 0);

        int rodadas_pai = this->rodadas[pai];
        this->rodadas[pai] = this->rodadas[maior];
        this->rodadas[maior] = rodadas_pai;

        refaz(maior, tam);
    }
    else
    {
        leMemLog((long int)&this->heap[pai], sizeof(URL_Acessos), 1);
        leMemLog((long int)&this->heap[maior], sizeof(URL_Acessos), 1);
    }
}