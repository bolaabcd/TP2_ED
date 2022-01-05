//---------------------------------------------------------------------
// Arquivo      : mergesort_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via mergesort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "mergesort_recursivo.hpp"

Mergesort_Recursivo::Mergesort_Recursivo() {}

void Mergesort_Recursivo::ordena()
{
    this->mergesort_interno(0, this->numero_urls - 1);
}

void Mergesort_Recursivo::mergesort_interno(int l, int r)
{
    if (l == r)
        return;
    int meio = (r + l) / 2;
    mergesort_interno(l, meio);
    mergesort_interno(meio + 1, r);

    for (int i = l, j = meio + 1; i <= meio && j < this->numero_urls; i++)
    {
        if (this->lista_urls[i] < this->lista_urls[j])
        {
            // Trocando elementos
            URL_Acessos a = this->lista_urls[i];
            this->lista_urls[i] = this->lista_urls[j];
            this->lista_urls[j] = a;
        }
        else
        {
            j++;
        }
    }
}