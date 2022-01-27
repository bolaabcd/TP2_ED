//---------------------------------------------------------------------
// Arquivo      : mergesort_nao_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via mergesort não recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "mergesort_nao_recursivo.hpp"
#include "pilha_par_int.hpp"
#include "fila_par_int.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

Mergesort_Nao_Recursivo::Mergesort_Nao_Recursivo()
// Descricao: construtor de Ordenadores que implementam heapsort recursivo.
// Entrada: nao tem.
// Saida: instância do tipo Heapsort_Recursivo.
{
}

void Mergesort_Nao_Recursivo::ordena()
// Descricao: ordena elementos segundo o algoritmo.
// Entrada: nao tem.
// Saida: ordena o array em this->lista_urls.
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

        erroAssert(l < r, "Intervalo invalido no mergesort nao recursivo.");

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

        erroAssert(l < r, "Intervalo invalido no mergesort nao recursivo.");

        URL_Acessos *lista_tmp = new URL_Acessos[this->numero_urls];

        int meio = (l + r) / 2;
        int k = 0;
        for (int i = l, j = meio + 1; k < this->numero_urls; k++)
        {
            if(k < l || k > r){
                lista_tmp[k] = this->lista_urls[k];
            } else if (j <= r && (i > meio || this->lista_urls[i] < this->lista_urls[j]))
            {
                leMemLog((long int)&this->lista_urls[i], sizeof(URL_Acessos), 1);
                leMemLog((long int)&this->lista_urls[j], sizeof(URL_Acessos), 1);
                lista_tmp[k] = this->lista_urls[j];
                j++;
            }
            else
            {
                leMemLog((long int)&this->lista_urls[i], sizeof(URL_Acessos), 1);
                leMemLog((long int)&this->lista_urls[j], sizeof(URL_Acessos), 1);
                lista_tmp[k] = this->lista_urls[i];
                i++;
            }
        }

        for(k = 0; k < this->numero_urls; k++){
            this->lista_urls[k] = lista_tmp[k];
        }

        delete[] lista_tmp;
    }
}