//---------------------------------------------------------------------
// Arquivo      : quicksort_recursivo.hpp
// Conteudo     : arquivo de cabeçalho para ordenação via quicksort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef QUICKSORT_RECURSIVO_ORDENATOR
#define QUICKSORT_RECURSIVO_ORDENATOR

#include "ordenador.hpp"

class Quicksort_Recursivo : public Ordenador
{
    public:
        Quicksort_Recursivo();
        void ordena() override;
};


#endif