//---------------------------------------------------------------------
// Arquivo      : fila_par_int.hpp
// Conteudo     : arquivo de cabeçalho para filha de par de inteiros.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef FILA_DE_PAR_DE_INTEIROS
#define FILA_DE_PAR_DE_INTEIROS

//Implementação por array
class Fila_Par_Int
{
    public:
        Fila_Par_Int(int capacidade);
        void adiciona(int a, int b);
        int primeiro_a();
        int primeiro_b();
        void tira_primeiro();
        bool vazia();
        void destruir();
        ~Fila_Par_Int();
    private:
        int capacidade;
        int quantidade;
        int* primeiro;
        int pos_init;
        int pos_final;
        int* segundo;
};


#endif