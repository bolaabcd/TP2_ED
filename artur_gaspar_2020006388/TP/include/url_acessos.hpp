//---------------------------------------------------------------------
// Arquivo      : url_acessos.hpp
// Conteudo     : arquivo de cabeçalho para classe que engloba quantidade
// de acessos e o URL em si.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#ifndef URL_ACESSOS
#define URL_ACESSOS

#include <string>
#include <iostream>

class URL_Acessos{
    public:
        std::string* url;
        int quantidade;
        bool operator<(URL_Acessos outro);
        friend std::istream operator>>(std::istream& in, URL_Acessos url_acessos);
        friend std::ostream operator<<(std::ostream& in, URL_Acessos url_acessos);
};

#endif