//---------------------------------------------------------------------
// Arquivo      : rodada_manipulator.hpp
// Conteudo     : arquivo de cabeçalho para manipular rodadas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef RODADA_MANIPULATOR
#define RODADA_MANIPULATOR

#include <string>
#include <fstream>
#include "ordenador.hpp"
#include "rodada_intercalator.hpp"

class Rodada_Manipulator
{
public:
    Rodada_Manipulator(
        std::string nome_entrada,
        Ordenador *ord,
        int num_rodadas,
        int n_mem_prim);
    void gera_rodadas();
    void intercala_rodadas(std::string nome_saida);
    bool acabou();
    void destruir();
    ~Rodada_Manipulator();

private:
    Ordenador *ord;
    std::ifstream arq_entrada;
    int num_rodadas;
    int n_mem_prim;
};

#endif