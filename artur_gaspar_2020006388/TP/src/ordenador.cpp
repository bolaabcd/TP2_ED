//---------------------------------------------------------------------
// Arquivo      : ordenador.cpp
// Conteudo     : arquivo de implementação para interface de ordenação.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "ordenador.hpp"

Ordenador::Ordenador(){}

void Ordenador::set_fonte(URL_Acessos* lista_urls, int numero_urls){
    this->lista_urls = lista_urls;
    this->numero_urls = numero_urls;
}

// O ponteiro usado não é alocado pelo ordenador, portanto não é preciso destruílo aqui.
Ordenador::~Ordenador(){}