//---------------------------------------------------------------------
// Arquivo      : rodada_intercalator.cpp
// Conteudo     : arquivo de implementação para intercalar rodadas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "rodada_intercalator.hpp"

Rodada_Intercalator::Rodada_Intercalator(int n_rodadas, std::string nome_saida) : nome_saida(nome_saida), heap_url_acessos(n_rodadas), num_rodadas(n_rodadas)
{
    this->fitas = new std::ifstream[n_rodadas];

    for (int i = 0; i < n_rodadas; i++)
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
        if(!fitas[i].good())
            break;
        this->heap_url_acessos.adicionar(url_acessos, i);
    }

    while (!this->heap_url_acessos.vazio())
    {
        URL_Acessos url_acessos = this->heap_url_acessos.url_acessos_primeiro();
        int rod_prim = this->heap_url_acessos.rodada_primeiro();
        this->heap_url_acessos.tira_primeiro();

        arq_saida << url_acessos << std::endl;
        
        fitas[rod_prim] >> url_acessos;

        if(!fitas[rod_prim].eof())
            this->heap_url_acessos.adicionar(url_acessos,rod_prim);
    }
}

void Rodada_Intercalator::destruir()
{
    if(this->fitas == nullptr)
        return;
    for (int i = 0; i < this->num_rodadas; i++)
    {
        this->fitas[i].close();
    }
    delete[] this->fitas;
    this->fitas = nullptr;
}

Rodada_Intercalator::~Rodada_Intercalator()
{
    destruir();
}