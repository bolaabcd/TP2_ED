//---------------------------------------------------------------------
// Arquivo      : quicksort_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via quicksort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "quicksort_recursivo.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

Quicksort_Recursivo::Quicksort_Recursivo()
// Descricao: construtor de Ordenadores que implementam heapsort recursivo.
// Entrada: nao tem.
// Saida: instância do tipo Heapsort_Recursivo.
{
}

void Quicksort_Recursivo::ordena()
// Descricao: ordena elementos segundo o algoritmo.
// Entrada: nao tem.
// Saida: ordena o array em this->lista_urls.
{
    quicksort_interno(0, this->numero_urls - 1);
}

void Quicksort_Recursivo::quicksort_interno(int l, int r)
// Descricao: funcao recursiva auxiliar para ordenamento, que reoderna o intervalo
// [l,r] do array.
// Entrada: extremos do intervalo [l,r] a ser ordenado.
// Saida: altera o array em this->lista_urls.
{
    if (l >= r)
        return;
    erroAssert(l < r, "Intervalo invalido no quicksort recursivo.");

    int meio = (l + r) / 2;
    int pivo = meio;
    if(this->lista_urls[l] < this->lista_urls[r]){
        if(this->lista_urls[meio] < this->lista_urls[l])
            pivo = l;
        else if (this->lista_urls[r] < this->lista_urls[meio])
            pivo = r;
    } else {
        if(this->lista_urls[meio] < this->lista_urls[r])
            pivo = r;
        else if (this->lista_urls[l] < this->lista_urls[meio])
            pivo = l;
    }

    URL_Acessos aux = this->lista_urls[pivo];
    leMemLog((long int)&this->lista_urls[pivo], sizeof(URL_Acessos), 0);
    int i, j;
    for (i = l, j = r;;)
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

    quicksort_interno(l, j);
    quicksort_interno(i, r);
}