//---------------------------------------------------------------------
// Arquivo      : url_acessos.cpp
// Conteudo     : arquivo de implementação para classe que engloba quantidade
// de acessos e o URL em si.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "url_acessos.hpp"

URL_Acessos::URL_Acessos() {}

bool URL_Acessos::operator<(URL_Acessos outro)
{
    if (this->quantidade == outro.quantidade)
        return this->url < outro.url;
    else
        return this->quantidade < outro.quantidade;
}

std::istream& operator>>(std::istream &in, URL_Acessos &url_acessos){
    in >> url_acessos.url >> url_acessos.quantidade;
    return in;
}

std::ostream& operator<<(std::ostream &out, URL_Acessos &url_acessos)
{
    out << url_acessos.url << " " << url_acessos.quantidade << std::endl;
    return out;
}
