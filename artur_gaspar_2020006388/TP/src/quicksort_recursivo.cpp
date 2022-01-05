//---------------------------------------------------------------------
// Arquivo      : quicksort_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via quicksort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "quicksort_recursivo.hpp"

Quicksort_Recursivo::Quicksort_Recursivo() {}

void Quicksort_Recursivo::ordena()
{
    quicksort_interno(0, this->numero_urls - 1);
}

void Quicksort_Recursivo::quicksort_interno(int l, int r)
{
    if (l >= r)
        return;
    int meio = (l + r) / 2;

    URL_Acessos aux = this->lista_urls[meio];
    int i, j;
    for (i = l, j = r;;)
    {
        for (; i <= j && aux < this->lista_urls[i]; i++);
        for (; i <= j && this->lista_urls[j] < aux; j--);

        if (i > j)
            break;

        //Trocando elementos
        URL_Acessos a = this->lista_urls[i];
        this->lista_urls[i++] = this->lista_urls[j];
        this->lista_urls[j--] = a;
    }

    quicksort_interno(l, j);
    quicksort_interno(i, r);
}