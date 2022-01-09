//---------------------------------------------------------------------
// Arquivo      : mergesort_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via mergesort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "mergesort_recursivo.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

Mergesort_Recursivo::Mergesort_Recursivo()
// Descricao: construtor de Ordenadores que implementam heapsort recursivo.
// Entrada: nao tem.
// Saida: instância do tipo Heapsort_Recursivo.
{
}

void Mergesort_Recursivo::ordena()
// Descricao: ordena elementos segundo o algoritmo.
// Entrada: nao tem.
// Saida: ordena o array em this->lista_urls.
{
    this->mergesort_interno(0, this->numero_urls - 1);
}

void Mergesort_Recursivo::mergesort_interno(int l, int r)
// Descricao: funcao auxiliar recursiva do mergesort.
// Entrada: extremos do intervalo de ordenacao [l, r] do passo atual.
// Saida: altera o array em this->lista_urls.
{
    if (l == r)
        return;
    erroAssert(l < r, "Intervalo invalido no mergesort recursivo.");

    int meio = (r + l) / 2;
    mergesort_interno(l, meio);
    mergesort_interno(meio + 1, r);

    for (int i = l, j = meio + 1; i <= meio && j < this->numero_urls; i++)
    {
        if (this->lista_urls[i] < this->lista_urls[j])
        {
            leMemLog((long int)&this->lista_urls[i], sizeof(URL_Acessos), 1);
            leMemLog((long int)&this->lista_urls[j], sizeof(URL_Acessos), 1);
            // Trocando elementos
            URL_Acessos a = this->lista_urls[i];
            leMemLog((long int)&this->lista_urls[i], sizeof(URL_Acessos), 0);
            this->lista_urls[i] = this->lista_urls[j];
            leMemLog((long int)&this->lista_urls[j], sizeof(URL_Acessos), 0);
            escreveMemLog((long int)&this->lista_urls[i], sizeof(URL_Acessos), 0);
            this->lista_urls[j] = a;
            escreveMemLog((long int)&this->lista_urls[j], sizeof(URL_Acessos), 0);
        }
        else
        {
            leMemLog((long int)&this->lista_urls[i], sizeof(URL_Acessos), 1);
            leMemLog((long int)&this->lista_urls[j], sizeof(URL_Acessos), 1);
            j++;
        }
    }
}