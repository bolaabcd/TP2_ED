//---------------------------------------------------------------------
// Arquivo      : ordenador.hpp
// Conteudo     : arquivo de cabeçalho para interface de ordenação.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef ORDENATOR_2000
#define ORDENATOR_2000

#include "url_acessos.hpp"

class Ordenador
{
public:
   Ordenador();
   void set_fonte(URL_Acessos* lista_urls, int numero_urls); 
   virtual void ordena();
protected:
    URL_Acessos* lista_urls;
    int numero_urls;
};


#endif