//---------------------------------------------------------------------
// Arquivo      : url_acessos.cpp
// Conteudo     : arquivo de implementação para classe que engloba quantidade
// de acessos e o URL em si.
// Autor        : Artur Gaspar da Silva
//---------------------------------------------------------------------

#include "url_acessos.hpp"

URL_Acessos::URL_Acessos()
// Descricao: construtor de URL_Acessos.
// Entrada: nao tem.
// Saida: instância do tipo URL_Acessos.
{
}

bool URL_Acessos::operator<(URL_Acessos outro)
// Descricao: comparador de URL_Acessos.
// Entrada: URL_Acessos a comparar com o atual.
// Saida: verdadeiro se a instancia em questao vem antes da recebida como
// argumento no ordenamento desejado.
{
    if (this->quantidade == outro.quantidade)
        return this->url < outro.url;
    else
        return this->quantidade < outro.quantidade;
}

std::istream &operator>>(std::istream &in, URL_Acessos &url_acessos)
// Descricao: leitor de stream do tipo URL_Acessos.
// Entrada: stream de entrada e tipo que sera preenchido segundo valores da stream.
// Saida: stream de entrada apos a leitura.
{
    return in >> url_acessos.url >> url_acessos.quantidade;
}

std::ostream &operator<<(std::ostream &out, URL_Acessos &url_acessos)
// Descricao: escritor em stream do tipo URL_Acessos.
// Entrada: stream de saida e tipo que sera escrito na stream.
// Saida: stream de saida apos a escrita.
{
    return out << url_acessos.url << " " << url_acessos.quantidade;
}
