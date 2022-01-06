//---------------------------------------------------------------------
// Arquivo      : ordenador.cpp
// Conteudo     : arquivo de implementação para interface de ordenação.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "ordenador.hpp"
#include "msgassert.hpp"

Ordenador::Ordenador()
// Descricao: construtor de Ordenadores que implementam heapsort recursivo.
// Entrada: nao tem.
// Saida: instância do tipo Heapsort_Recursivo.
{
}

void Ordenador::set_fonte(URL_Acessos *lista_urls, int numero_urls)
// Descricao: registra o array a ser ordenado e seu tamanho.
// Entrada: nao tem.
// Saida: registra os atributos correspondentes.
{
    erroAssert(numero_urls >= 0, "Numero de URLs a ordenar nao pode ser negativo.");
    this->lista_urls = lista_urls;
    this->numero_urls = numero_urls;
}

void Ordenador::ordena()
// Descricao: metodo vazio de ordenacao a ser sobrescrito.
// Entrada: nao tem.
// Saida: nao tem.
{
}

// O ponteiro usado não é alocado pelo ordenador, portanto não é preciso destruílo aqui.
Ordenador::~Ordenador()
// Descricao: destrutor padrao do Ordenador.
// Entrada: nao tem.
// Saida: nao tem.
{
}