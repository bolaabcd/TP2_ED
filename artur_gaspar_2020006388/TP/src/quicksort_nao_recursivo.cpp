//---------------------------------------------------------------------
// Arquivo      : quicksort_nao_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via quicksort não recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "quicksort_nao_recursivo.hpp"
#include "pilha_par_int.hpp"
#include "msgassert.hpp"

Quicksort_Nao_Recursivo::Quicksort_Nao_Recursivo()
// Descricao: construtor de Ordenadores que implementam heapsort recursivo.
// Entrada: nao tem.
// Saida: instância do tipo Heapsort_Recursivo.
{
}

void Quicksort_Nao_Recursivo::ordena()
// Descricao: ordena elementos segundo o algoritmo.
// Entrada: nao tem.
// Saida: ordena o array em this->lista_urls.
{
    Pilha_Par_Int a_processar(this->numero_urls);
    a_processar.adiciona(0, this->numero_urls - 1);
    while (!a_processar.vazia())
    {
        int l = a_processar.topo_a();
        int r = a_processar.topo_b();
        a_processar.tira_topo();

        if (l >= r)
            continue;
        erroAssert(l < r, "Intervalo invalido no quicksort nao recursivo.");

        int meio = (l + r) / 2;
        URL_Acessos aux = this->lista_urls[meio];
        int i, j;
        for (i = l, j = r; i <= j;)
        {
            for (; i <= j && aux < this->lista_urls[i]; i++)
                ;
            for (; i <= j && this->lista_urls[j] < aux; j--)
                ;
            if (i > j)
                break;

            // Trocando elementos
            URL_Acessos a = this->lista_urls[i];
            this->lista_urls[i++] = this->lista_urls[j];
            this->lista_urls[j--] = a;
        }
        a_processar.adiciona(l, j);
        a_processar.adiciona(i, r);
    }
}