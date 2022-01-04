//---------------------------------------------------------------------
// Arquivo      : heap_url_acessos.cpp
// Conteudo     : arquivo de implementação para heap de url_acessoss.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "heap_url_acessos.hpp"
#include "url_acessos.hpp"
#include "msgassert.hpp"

Heap_URL_Acessos::Heap_URL_Acessos(int num_elementos)
{
    this->capacidade = num_elementos;
    this->quantidade = 0;
    this->heap = new URL_Acessos[num_elementos + 1];
    this->rodadas = new int[num_elementos + 1];
}

void Heap_URL_Acessos::adicionar(URL_Acessos url_acessos, int rodada)
{
    this->rodadas[++this->quantidade] = rodada;
    this->heap[this->quantidade] = url_acessos;

    for (int i = this->quantidade / 2; i > 0; i /= 2)
        refaz(i, this->quantidade);
}

URL_Acessos Heap_URL_Acessos::url_acessos_primeiro()
{
    return this->heap[1];
}

int Heap_URL_Acessos::rodada_primeiro()
{
    return this->rodadas[1];
}

void Heap_URL_Acessos::tira_primeiro()
{
    heap[1] = heap[this->quantidade];
    rodadas[1] = rodadas[this->quantidade--];
    refaz(1, this->quantidade);
}

bool Heap_URL_Acessos::vazio()
{
    return this->quantidade == 0;
}

Heap_URL_Acessos::~Heap_URL_Acessos()
{
    if (this->capacidade <= 0)
        return;
    this->capacidade = 0;
    this->quantidade = 0;
    delete[] this->heap;
    delete[] this->rodadas;
}

void Heap_URL_Acessos::refaz(int l, int tam) {
    int pai = l; 
    URL_Acessos filhoR, filhoL;
    if (2*l+1 <= tam) {
        filhoL = this->heap[2*l+1];
        filhoR = this->heap[2*l];
    } else if (2*l <= tam) {
        filhoR = this->heap[2*l];
    } else {
        return;
    }

    int maior = 2*l+1;

    if (filhoL < filhoR) {
        maior = 2*l;
    }

    if (this->heap[pai] < this->heap[maior]) {
        // Trocando elementos
        URL_Acessos url_pai = this->heap[pai];
        this->heap[pai] = this->heap[maior];
        this->heap[maior] = url_pai;
        
        int rodadas_pai = this->rodadas[pai];
        this->rodadas[pai] = this->rodadas[maior];
        this->rodadas[maior] = rodadas_pai;

        refaz(maior,tam);
    }
}