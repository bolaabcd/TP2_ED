//---------------------------------------------------------------------
// Arquivo      : rodada_manipulator.cpp
// Conteudo     : implementacao do tipo Rodada_Manipulator.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "rodada_manipulator.hpp"
#include "url_acessos.hpp"

Rodada_Manipulator::Rodada_Manipulator(
    std::string nome_entrada,
    Ordenador ord,
    int num_rodadas,
    int num_entidades) : ord(ord),
                         num_rodadas(num_rodadas),
                         n_mem_prim(n_mem_prim)
{
    this->arq_entrada.open(nome_entrada);
}

void Rodada_Manipulator::gera_rodadas()
{
    for (int k = 0; k < this->num_rodadas; k++)
    {
        URL_Acessos *url_acessos = (URL_Acessos *)malloc(this->n_mem_prim * sizeof(URL_Acessos));
        int i;
        for (i = 0; i < this->n_mem_prim && !this->arq_entrada.eof(); i++)
        {
            this->arq_entrada >> url_acessos[i];
        }

        this->ord.set_fonte(url_acessos, i);
        this->ord.ordena();

        std::ofstream arq_saida;
        arq_saida.open("rodada-" + std::to_string(k + 1) + ".txt");

        for (int j = 0; j < i; j++)
        {
            arq_saida << url_acessos[j] << std::endl;
        }
        arq_saida.close();
        free(url_acessos);
    }
}

void Rodada_Manipulator::intercala_rodadas(std::string nome_saida)
{
    Rodada_Intercalator intercal(this->num_rodadas);
    intercal.intercalar();
    intercal.destruir();
}

bool Rodada_Manipulator::acabou()
{
    return this->arq_entrada.eof();
}

void Rodada_Manipulator::destruir()
{
    this->arq_entrada.close();
}

Rodada_Manipulator::~Rodada_Manipulator()
{
    this->destruir();
}