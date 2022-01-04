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
    void adicionar(URL_Acessos url_acessos, int rodada);
    URL_Acessos url_acessos_primeiro();
    int rodada_primeiro();
    void tira_primeiro();
    bool vazio();
    ~Heap_URL_Acessos();

private:
    int capacidade;
    int quantidade;
    URL_Acessos *heap;
    int *rodadas;
};

#endif