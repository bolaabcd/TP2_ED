//---------------------------------------------------------------------
// Arquivo      : quicksort_nao_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via quicksort não recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "quicksort_nao_recursivo.hpp"
#include "pilha_par_int.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

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
        leMemLog((long int)&this->lista_urls[meio], sizeof(URL_Acessos), 0);
        int i, j;
        for (i = l, j = r; i <= j;)
        {
            for (; i <= j && aux < this->lista_urls[i]; i++)
                leMemLog((long int)&this->lista_urls[i], sizeof(URL_Acessos), 1);
            for (; i <= j && this->lista_urls[j] < aux; j--)
                leMemLog((long int)&this->lista_urls[j], sizeof(URL_Acessos), 1);
            if (i > j)
                break;

            // Trocando elementos
            URL_Acessos a = this->lista_urls[i];
            leMemLog((long int)&this->lista_urls[i], sizeof(URL_Acessos), 0);
            this->lista_urls[i++] = this->lista_urls[j];
            leMemLog((long int)&this->lista_urls[j], sizeof(URL_Acessos), 0);
            escreveMemLog((long int)&this->lista_urls[i - 1], sizeof(URL_Acessos), 0);
            this->lista_urls[j--] = a;
            escreveMemLog((long int)&this->lista_urls[j + 1], sizeof(URL_Acessos), 0);
        }
        a_processar.adiciona(l, j);
        a_processar.adiciona(i, r);
    }
}