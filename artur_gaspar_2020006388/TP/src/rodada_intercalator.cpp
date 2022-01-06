//---------------------------------------------------------------------
// Arquivo      : rodada_intercalator.cpp
// Conteudo     : arquivo de implementação para intercalar rodadas.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "rodada_intercalator.hpp"
#include "msgassert.hpp"

Rodada_Intercalator::Rodada_Intercalator(int n_rodadas, std::string nome_saida) : nome_saida(nome_saida), heap_url_acessos(n_rodadas), num_rodadas(n_rodadas)
// Descricao: construtor do intercalador de rodadas.
// Entrada: numero maximo de rodadas aceitos e nome do arquivo de saida.
// Saida: instância do tipo Rodada_Intercalator.
{
    erroAssert(n_rodadas > 0, "O numero de rodadas a intercalar deve ser positivo.");
    this->fitas = new std::ifstream[n_rodadas];

    for (int i = 0; i < n_rodadas; i++)
    {
        this->fitas[i].open("rodada-" + std::to_string(i + 1) + ".txt");
        erroAssert(!this->fitas[i].fail(), "Erro ao abrir arquivo de fita.");
    }
}

void Rodada_Intercalator::intercalar()
// Descricao: intercala as fitas.
// Entrada: le dos arquivos de fita (rodada-x.txt).
// Saida: altera o arquivo de saida.
{
    std::ofstream arq_saida;
    arq_saida.open(this->nome_saida);
    erroAssert(!arq_saida.fail(), "Erro ao abrir arquivo de saida.");

    for (int i = 0; i < this->num_rodadas; i++)
    {
        URL_Acessos url_acessos;
        fitas[i] >> url_acessos;
        if (!fitas[i].good())
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

        if (!fitas[rod_prim].eof())
            this->heap_url_acessos.adicionar(url_acessos, rod_prim);
    }
}

void Rodada_Intercalator::destruir()
// Descricao: destroi o manipulador de rodadas.
// Entrada: nao tem.
// Saida: nao tem.
{
    if (this->fitas == nullptr)
        return;
    for (int i = 0; i < this->num_rodadas; i++)
    {
        this->fitas[i].close();
    }
    delete[] this->fitas;
    this->fitas = nullptr;
}

Rodada_Intercalator::~Rodada_Intercalator()
// Descricao: destrutor padrao do manipulador de rodadas.
// Entrada: nao tem.
// Saida: nao tem.
{
    destruir();
}