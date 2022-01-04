//---------------------------------------------------------------------
// Arquivo      : mergesort_nao_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via mergesort não recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "mergesort_nao_recursivo.hpp"
#include "pilha_par_int.hpp"
#include "fila_par_int.hpp"

Mergesort_Nao_Recursivo::Mergesort_Nao_Recursivo() {}

void Mergesort_Nao_Recursivo::ordena()
{
    Pilha_Par_Int a_processar(this->numero_urls);
    Fila_Par_Int a_adicionar(this->numero_urls * 3);

    a_adicionar.adiciona(0, this->numero_urls - 1);
    while (!a_adicionar.vazia())
    {
        int l = a_adicionar.primeiro_a();
        int r = a_adicionar.primeiro_b();
        a_adicionar.tira_primeiro();

        if (l == r)
            continue;

        a_processar.adiciona(l, r);

        int meio = (l + r) / 2;
        a_adicionar.adiciona(l, meio);
        a_adicionar.adiciona(meio + 1, r);
    }

    while (!a_processar.vazia())
    {
        int l = a_processar.topo_a();
        int r = a_processar.topo_b();
        a_processar.tira_topo();

        int meio = (l + r) / 2;

        for (int i = l, j = meio + 1; i <= meio && j < this->numero_urls; i++)
        {
            if (this->lista_urls[i] < this->lista_urls[j])
            {
                // Trocando elementos
                URL_Acessos a = this->lista_urls[i];
                this->lista_urls[i] = this->lista_urls[j];
                this->lista_urls[j++] = a;
            }
        }
    }
}