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

    URL_Acessos *lista_tmp = new URL_Acessos[this->numero_urls];
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