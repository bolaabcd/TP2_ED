//---------------------------------------------------------------------
// Arquivo      : heap_string.hpp
// Conteudo     : arquivo de cabeçalho para heap de strings.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef HEAP_STRING
#define HEAP_STRING

#include <string>
#include <fstream>
#include "heap_string.hpp"

class Heap_String
{
public:
    Heap_String(int num_elementos);
    std::string adicionar(std::string string);
    std::string pega_primeiro();
    void tira_primeiro();
    ~Heap_String();

private:
    int capacidade;
    int quantidade;
    std::string *heap;
};

#endif