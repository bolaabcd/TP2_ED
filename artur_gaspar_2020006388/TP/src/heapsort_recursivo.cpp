//---------------------------------------------------------------------
// Arquivo      : heapsort_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via heapsort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "heapsort_recursivo.hpp"
#include "url_acessos.hpp"
#include "msgassert.hpp"

Heapsort_Recursivo::Heapsort_Recursivo()
// Descricao: construtor de Ordenadores que implementam heapsort recursivo.
// Entrada: nao tem.
// Saida: instância do tipo Heapsort_Recursivo.
{
}

void Heapsort_Recursivo::ordena()
// Descricao: ordena elementos segundo o algoritmo.
// Entrada: nao tem.
// Saida: ordena o array em this->lista_urls.
{
    for (int esq = (this->numero_urls) / 2 + 1; esq >= 1; esq--)
    {
        this->refaz(esq, this->numero_urls);
    }

    for (int dir = (this->numero_urls); dir > 1;)
    {
        // Trocando elementos
        URL_Acessos primeiro = this->lista_urls[1 - 1];
        this->lista_urls[1 - 1] = this->lista_urls[dir - 1];
        this->lista_urls[-1 + dir--] = primeiro;

        this->refaz(1, dir);
    }
}

void Heapsort_Recursivo::refaz(int l, int tam)
// Descricao: funcao auxiliar que arruma um galho do heap a partir de l.
// Entrada: posicao inicial a refazer e tamanho total do heap.
// Saida: altera o this->heap e o this->rodadas.
{
    erroAssert((l >= 1 && l <= tam), "Valores invalidos para o algoritmo de heap.");

    int pai = l;
    URL_Acessos filhoR, filhoL;
    int menor = 2 * l;

    if (2 * l + 1 <= tam)
    {
        filhoL = this->lista_urls[2 * l + 1 - 1];
        filhoR = this->lista_urls[2 * l - 1];
        if (filhoL < filhoR)
        {
            menor = 2 * l + 1;
        }
    }
    else if (2 * l <= tam)
    {
        filhoR = this->lista_urls[2 * l - 1];
    }
    else
    {
        return;
    }

    if (this->lista_urls[menor - 1] < this->lista_urls[pai - 1])
    {
        // Trocando elementos
        URL_Acessos url_pai = this->lista_urls[pai - 1];
        this->lista_urls[pai - 1] = this->lista_urls[menor - 1];
        this->lista_urls[menor - 1] = url_pai;

        refaz(menor, tam);
    }
}