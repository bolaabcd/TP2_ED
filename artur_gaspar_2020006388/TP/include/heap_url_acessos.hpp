//---------------------------------------------------------------------
// Arquivo      : heap_string.hpp
// Conteudo     : arquivo de cabeçalho para heap de strings.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef HEAP_URL_ACESSOS
#define HEAP_URL_ACESSOS

#include "url_acessos.hpp"
#include <fstream>

class Heap_URL_Acessos
{
public:
    Heap_URL_Acessos(int num_elementos);
    URL_Acessos adicionar(URL_Acessos url_acessos);
    URL_Acessos pega_primeiro();
    void tira_primeiro();
    ~Heap_URL_Acessos();

private:
    int capacidade;
    int quantidade;
    URL_Acessos *heap;
};

#endif