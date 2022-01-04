//---------------------------------------------------------------------
// Arquivo      : ordenador.hpp
// Conteudo     : arquivo de cabeçalho para interface de ordenação.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef ORDENATOR_2000
#define ORDENATOR_2000

#include <string>

class Ordenador
{
public:
   Ordenador();
   void set_fonte(std::string* lista_urls, int numero_urls); 
   virtual void ordena();
protected:
    std::string* lista_urls;
    int numero_urls;
};


#endif