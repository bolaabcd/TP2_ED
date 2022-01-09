//---------------------------------------------------------------------
// Arquivo      : rodada_manipulator.cpp
// Conteudo     : implementacao do tipo Rodada_Manipulator.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "rodada_manipulator.hpp"
#include "url_acessos.hpp"
#include "msgassert.hpp"
#include "memlog.hpp"

Rodada_Manipulator::Rodada_Manipulator(
    std::string nome_entrada,
    Ordenador *ord,
    int num_rodadas,
    int n_mem_prim) : ord(ord),
                      num_rodadas(num_rodadas),
                      n_mem_prim(n_mem_prim)
// Descricao: construtor do manipulador de rodadas.
// Entrada: numero maximo de rodadas aceitos, numero maximo de elementos aceitos
// na memoria primaria, ordenador a ser utilizado e nome do arquivo de entrada.
// Saida: instância do tipo Rodada_Manipulator.
{
    erroAssert(num_rodadas > 0, "O numero de rodadas do manipulador deve ser positivo.");
    erroAssert(n_mem_prim > 0, "O numero de elementos aceitos na memoria primaria deve ser positivo.");

    this->arq_entrada.open(nome_entrada);
    erroAssert(!this->arq_entrada.fail(), "Erro ao abrir arquivo de entrada.");
}

void Rodada_Manipulator::gera_rodadas()
// Descricao: gera as fitas.
// Entrada: le do arquivo de entrada.
// Saida: escreve nos arquivos de rodadas (rodada-x.txt).
{
    for (int k = 0; k < this->num_rodadas; k++)
    {
        URL_Acessos *url_acessos = new URL_Acessos[this->n_mem_prim];
        int i;
        bool leu_algo = false;
        for (i = 0; i < this->n_mem_prim; i++)
        {
            this->arq_entrada >> url_acessos[i];
            escreveMemLog((long int)&url_acessos[i], sizeof(URL_Acessos));
            if (this->arq_entrada.eof())
                break;
            leu_algo = true;
        }

        std::ofstream arq_saida;
        arq_saida.open("rodada-" + std::to_string(k + 1) + ".txt");
        erroAssert(!arq_saida.fail(), "Erro ao abrir arquivo de rodada para escrita.");

        if (!leu_algo)
            break;
        this->ord->set_fonte(url_acessos, i);
        this->ord->ordena();

        for (int j = 0; j < i; j++)
        {
            arq_saida << url_acessos[j] << std::endl;
            leMemLog((long int)&url_acessos[j], sizeof(URL_Acessos));
        }
        arq_saida.close();
        delete[] url_acessos;
    }
}

void Rodada_Manipulator::intercala_rodadas(std::string nome_saida)
// Descricao: intercala as fitas.
// Entrada: le dos arquivos de fita (rodada-x.txt).
// Saida: altera o arquivo de saida.
{
    Rodada_Intercalator intercal(this->num_rodadas, nome_saida);
    intercal.intercalar();
    intercal.destruir();
}

bool Rodada_Manipulator::acabou()
// Descricao: informa se ainda ha algo a ler no arquivo de entrada.
// Entrada: nao tem.
// Saida: verdadeiro se o arquivo de entrada acabou, falso caso contrario.
{
    return this->arq_entrada.eof();
}

void Rodada_Manipulator::destruir()
// Descricao: destroi o manipulador de rodadas.
// Entrada: nao tem.
// Saida: nao tem.
{
    this->arq_entrada.close();
}

Rodada_Manipulator::~Rodada_Manipulator()
// Descricao: destrutor padrao do manipulador de rodadas.
// Entrada: nao tem.
// Saida: nao tem.
{
    this->destruir();
}