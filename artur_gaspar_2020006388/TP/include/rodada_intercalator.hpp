//---------------------------------------------------------------------
// Arquivo      : rodada_intercalator.hpp
// Conteudo     : arquivo de cabeçalho para intercalar rodadas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef RODADA_INTERCALATOR
#define RODADA_INTERCALATOR

#include <string>
#include <fstream>
#include "heap_string.hpp"

class Rodada_Intercalator
{
public:
    Rodada_Intercalator(int num_rodadas);
    void intercalar();
    ~Rodada_Intercalator();
private:
    std::ofstream* fitas;
    Heap_String heap_string;
};


#endif