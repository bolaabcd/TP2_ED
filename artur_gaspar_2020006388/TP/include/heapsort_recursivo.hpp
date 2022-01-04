//---------------------------------------------------------------------
// Arquivo      : heapsort_recursivo.hpp
// Conteudo     : arquivo de cabeçalho para ordenação via heapsort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef HEAPSORT_RECURSIVO_ORDENATOR
#define HEAPSORT_RECURSIVO_ORDENATOR

#include "ordenador.hpp"

class Heapsort_Recursivo : public Ordenador
{
    public:
        Heapsort_Recursivo();
        void ordena() override;
};


#endif