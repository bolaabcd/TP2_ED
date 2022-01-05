//---------------------------------------------------------------------
// Arquivo      : ordena.cpp
// Conteudo     : arquivo principal do programa ordena
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include <iostream>
#include <getopt.h>
#include <string>
#include "memlog.hpp"
#include "msgassert.hpp"
#include "rodada_manipulator.hpp"
#include "ordenador.hpp"
#include "quicksort_recursivo.hpp"
#include "quicksort_nao_recursivo.hpp"
#include "mergesort_recursivo.hpp"
#include "mergesort_nao_recursivo.hpp"
#include "heapsort_recursivo.hpp"

// definicoes dos modos de ordenamento
#define MERGE_RECURSIVO 1
#define HEAP_RECURSIVO 2
#define QUICK_NRECURSIVO 3
#define MERGE_NRECURSIVO 4

// variaveis globais para opcoes
static int desafio, n_fitas, n_mem_prim;
std::string reg_nome, in_nome, out_nome;
int regmem;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
    fprintf(stderr, "ordena\n");
    fprintf(stderr, "\t-h      \t(obter ajuda) \n");
    fprintf(stderr, "\t-i <arq>\t(arquivo de entrada) \n");
    fprintf(stderr, "\t-o <arq>\t(arquivo de saida)) \n");
    fprintf(stderr, "\t-n <num>\t(limite de entidades na memoria primaria: maximo por fita)\n");
    fprintf(stderr, "\t-f <num>\t(limite de fitas, preenche cada fita ate ter esse numero de fitas)\n");
    fprintf(stderr, "\t-d      \t[1_merge, 1_heap, 2_quick, 2_merge]\t(desafio a executar)\n");
    fprintf(stderr, "\t-p      \t<arq>\t(arquivo de registro de desempenho)\n");
    fprintf(stderr, "\t-l      \t(registrar padrao de acesso e localidade)\n");
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
    n_fitas = -1;
    n_mem_prim = -1;
    regmem = 0;
    reg_nome[0] = 0;
    in_nome[0] = 0;
    out_nome[0] = 0;
    std::string d_nome;
    bool p = false, o = false, i = false, f = false, n = false;

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "d:n:f:p:i:o:hl")) != EOF)
    {
        switch (c)
        {
        case 'f':
            avisoAssert(!f, "Mais de uma quantidade de fitas passada: o ultimo valor sera utilizado.");
            f = true;
            n_fitas = atoi(optarg);
            break;
        case 'n':
            avisoAssert(!n, "Mais de uma quantidade de entidades passada: o ultimo valor sera utilizado.");
            n = true;
            n_mem_prim = atoi(optarg);
            break;
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
            avisoAssert(desafio != -1, "Desafio invalido passado como argumento, ignorando...");
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
    erroAssert(f,
                "ordena - eh necessario informar a quantidade de fitas.");
    erroAssert(n, 
                "ordena - eh necessario informar a quantidade de entidades por fita.");
    erroAssert(n_mem_prim > 0, 
                "ordena - quantidade de entidades por fita invalida.");
    erroAssert(n_fitas > 0, 
                "ordena - quantidade de fitas invalida.");
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

    Ordenador *ord;
    Quicksort_Recursivo qr = Quicksort_Recursivo();
    Mergesort_Recursivo mr = Mergesort_Recursivo();
    Mergesort_Nao_Recursivo mn = Mergesort_Nao_Recursivo();
    Quicksort_Nao_Recursivo qn = Quicksort_Nao_Recursivo();
    Heapsort_Recursivo hr = Heapsort_Recursivo();

    switch (desafio)
    {
    case MERGE_RECURSIVO:
        ord = &mr;
        break;
    case HEAP_RECURSIVO:
        ord = &hr;
        break;
    case QUICK_NRECURSIVO:
        ord = &qn;
        break;
    case MERGE_NRECURSIVO:
        ord = &mn;
        break;
    default:
        ord = &qr;
        break;
    }

    Rodada_Manipulator manipulator(in_nome, ord, n_fitas, n_mem_prim);

    while(!manipulator.acabou()){
        manipulator.gera_rodadas();
        manipulator.intercala_rodadas(out_nome);
    }

    manipulator.destruir();

    // conclui registro de acesso
    return finalizaMemLog();
}
