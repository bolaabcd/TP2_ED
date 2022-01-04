//---------------------------------------------------------------------
// Arquivo      : rodada_intercalator.cpp
// Conteudo     : arquivo de implementação para intercalar rodadas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "rodada_intercalator.hpp"

Rodada_Intercalator::Rodada_Intercalator(int num_rodadas, std::string nome_saida) : heap_url_acessos(num_rodadas), num_rodadas(num_rodadas), nome_saida(nome_saida)
{
    this->fitas = (std::ifstream *)malloc(num_rodadas * sizeof(URL_Acessos));

    for (int i = 0; i < num_rodadas; i++)
    {
        this->fitas[i].open("rodada-" + std::to_string(i + 1) + ".txt");
    }
}

void Rodada_Intercalator::intercalar()
{
    std::ofstream arq_saida;
    arq_saida.open(this->nome_saida);

    for (int i = 0; i < this->num_rodadas; i++)
    {
        URL_Acessos url_acessos;
        fitas[i] >> url_acessos;
        this->heap_url_acessos.adicionar(url_acessos, i);
    }

    while (!this->heap_url_acessos.vazio())
    {
        URL_Acessos url_acessos = this->heap_url_acessos.url_acessos_primeiro();
        int rod_prim = this->heap_url_acessos.rodada_primeiro();
        this->heap_url_acessos.tira_primeiro();

        arq_saida << url_acessos;
        
        fitas[rod_prim] >> url_acessos;

        if(!fitas[rod_prim].eof())
            this->heap_url_acessos.adicionar(url_acessos,rod_prim);
    }
}

void Rodada_Intercalator::destruir()
{
    for (int i = 0; i < this->num_rodadas; i++)
    {
        this->fitas[i].close();
    }
    free(this->fitas);
}

Rodada_Intercalator::~Rodada_Intercalator()
{
    destruir();
}