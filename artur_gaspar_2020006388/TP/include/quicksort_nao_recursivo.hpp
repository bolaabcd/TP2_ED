//---------------------------------------------------------------------
// Arquivo      : quicksort_nao_recursivo.hpp
// Conteudo     : arquivo de cabeçalho para ordenação via quicksort não recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef QUICKSORT_NAO_RECURSIVO_ORDENATOR
#define QUICKSORT_NAO_RECURSIVO_ORDENATOR

#include "ordenador.hpp"

class Quicksort_Nao_Recursivo : public Ordenador
{
public:
    Quicksort_Nao_Recursivo();
    void ordena() override;
};

#endif