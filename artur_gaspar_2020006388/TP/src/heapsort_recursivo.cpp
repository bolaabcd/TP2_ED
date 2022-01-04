//---------------------------------------------------------------------
// Arquivo      : heapsort_recursivo.cpp
// Conteudo     : arquivo de implementação para ordenação via heapsort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "heapsort_recursivo.hpp"
#include "url_acessos.hpp"

Heapsort_Recursivo::Heapsort_Recursivo(){}

void Heapsort_Recursivo::ordena(){    
    for (int esq = (this->numero_urls)/2+1; esq >= 1; esq--) {
        refaz(esq,this->numero_urls);
    }

    for (int dir = (this->numero_urls); dir > 1; ) {
        // Trocando elementos
        URL_Acessos primeiro = this->lista_urls[1-1];
        this->lista_urls[1-1] = this->lista_urls[dir-1];
        this->lista_urls[-1+dir--] = primeiro; 

        refaz(1, dir);
    }
}

void Heapsort_Recursivo::refaz(int l, int tam){
    int pai = l;
    URL_Acessos filhoR, filhoL;
    if (2*l+1 <= tam) {
        filhoL = this->lista_urls[2*l+1-1];
        filhoR = this->lista_urls[2*l-1];
    } else if (2*l <= tam) {
        filhoR = this->lista_urls[2*l-1];
    } else {
        return;
    }

    int maior = 2*l+1;

    if (filhoL < filhoR) {
        maior = 2*l;
    }

    if (this->lista_urls[pai-1] < this->lista_urls[maior-1]) {
        // Trocando elementos
        URL_Acessos url_pai = this->lista_urls[pai-1];
        this->lista_urls[pai-1] = this->lista_urls[maior-1];
        this->lista_urls[maior-1] = url_pai;

        refaz(maior,tam);
    }
}