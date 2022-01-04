//---------------------------------------------------------------------
// Arquivo      : rodada_intercalator.hpp
// Conteudo     : arquivo de cabeçalho para intercalar rodadas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef RODADA_INTERCALATOR
#define RODADA_INTERCALATOR

#include <fstream>
#include "heap_url_acessos.hpp"

class Rodada_Intercalator
{
public:
    Rodada_Intercalator(int num_rodadas, std::string nome_saida);
    void intercalar();
    void destruir();
    ~Rodada_Intercalator();
private:
    std::ifstream* fitas;
    std::string nome_saida;
    Heap_URL_Acessos heap_url_acessos;
    int num_rodadas;
};


#endif