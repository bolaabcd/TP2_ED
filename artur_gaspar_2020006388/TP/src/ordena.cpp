//---------------------------------------------------------------------
// Arquivo      : ordena.cpp
// Conteudo     : arquivo principal do programa ordena
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include <iostream>
#include <getopt.h>
#include <string>
#include "memlog.h"
#include "msgassert.h"

// definicoes dos modos de ordenamento
#define MERGE_RECURSIVO 1
#define HEAP_RECURSIVO 2
#define QUICK_NRECURSIVO 3
#define MERGE_NRECURSIVO 4

// variaveis globais para opcoes
static int desafio;
std::string reg_nome, in_nome, out_nome;
int regmem;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
    fprintf(stderr, "ordena\n");
    fprintf(stderr, "\t-h \t\t(obter ajuda) \n");
    fprintf(stderr, "\t-i <arq>\t\t(arquivo de entrada) \n");
    fprintf(stderr, "\t-o <arq>\t\t(arquivo de saida)) \n");
    fprintf(stderr, "\t-n <num>\t\t(numero total de entidades)\n");
    fprintf(stderr, "\t-f <num>\t\t(numero de fitas)\n");
    fprintf(stderr, "\t-d \t\t[1_merge, 1_heap, 2_quick, 2_merge]\t(desafio a executar)\n");
    fprintf(stderr, "\t-p \t\t<arq>\t(arquivo de registro de desempenho)\n");
    fprintf(stderr, "\t-l \t\t(registrar padrao de acesso e localidade)\n");
}

void parse_args(int argc, char **argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty, regmem, lognome
{
    // tratando caso de nao ter argumentos
    if (argc == 1)
    {
        uso();
        exit(1);
    }

    // variavel externa do getopt
    extern char *optarg;

    // variavel auxiliar
    int c;

    // inicializacao variaveis globais para opcoes
    desafio = -1;
    regmem = 0;
    reg_nome[0] = 0;
    in_nome[0] = 0;
    out_nome[0] = 0;
    std::string d_nome;
    bool p = false, o = false, i = false;

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "smtp:1:2:lo:h")) != EOF)
    {
        switch (c)
        {
        case 'd':
            avisoAssert(desafio == -1, "Mais de um desafio escolhido: o ultimo sera utilizado.");
            d_nome = optarg;
            if (d_nome == "1_merge")
                desafio = MERGE_RECURSIVO;
            else if (d_nome == "1_heap") 
                desafio = HEAP_RECURSIVO;
            else if (d_nome == "2_quick")
                desafio = QUICK_NRECURSIVO;
            else if (d_nome == "2_merge")
                desafio = MERGE_NRECURSIVO;
            avisoAssert(desafio!=-1, "Desafio invalido passado como argumento.");
            break;
        case 'p':
            avisoAssert(!p, "Mais de um arquivo de registro passado, o ultimo sera usado.");
            p = true;
            reg_nome = optarg;
            break;
        case 'l':
            regmem = 1;
            break;
        case 'o':
            avisoAssert(!o, "Mais de um arquivo de saida passado, o ultimo sera usado.");
            o = true;
            out_nome = optarg;
            break;
        case 'i':
            avisoAssert(!i, "Mais de um arquivo de entrada passado, o ultimo sera usado.");
            i = true;
            in_nome = optarg;
            break;
        case 'h':
        default:
            uso();
            exit(1);
        }
    }
    // verificacao da consistencia das opcoes
    erroAssert(reg_nome.length() > 0,
               "ordena - nome de arquivo de registro de acesso tem que ser definido.");
    erroAssert(in_nome.length() > 0,
               "ordena - nome de arquivo de entrada tem que ser definido.");
    erroAssert(out_nome.length() > 0,
               "ordena - nome de arquivo de saida tem que ser definido.");
}

int main(int argc, char **argv)
// Descricao: programa principal para ordenacao externa de URLs
// Entrada: argc e argv
// Saida: no arquivo especificado escreve o resultado ordenado
{
    // avaliar linha de comando
    parse_args(argc, argv);

    // iniciar registro de acesso
    iniciaMemLog(reg_nome, regmem);

    // ativar registro de acesso
    ativaMemLog();

    
    // conclui registro de acesso
    return finalizaMemLog();
}
