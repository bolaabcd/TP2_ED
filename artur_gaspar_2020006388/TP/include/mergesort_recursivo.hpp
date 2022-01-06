//---------------------------------------------------------------------
// Arquivo      : mergesort_recursivo.hpp
// Conteudo     : arquivo de cabeçalho para ordenação via mergesort recursivo.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef MERGE_RECURSIVO_ORDENATOR
#define MERGE_RECURSIVO_ORDENATOR

#include "ordenador.hpp"

class Mergesort_Recursivo : public Ordenador
{
public:
    Mergesort_Recursivo();
    void ordena() override;

private:
    void mergesort_interno(int l, int r);
};

#endif