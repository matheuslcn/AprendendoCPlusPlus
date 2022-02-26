#include <regex>
#include <string>

#ifndef VALIDADOR_H
#define VALIDADOR_H

using namespace std;


int validaCpf (string cpf)
{
    /*
    if (cpf.length()!=9) return 0;
    for (int i=0; i<9; i++)
        if (cpf[i] < '0' || cpf[i] > '9') return 0;
    return 1;
    */
    regex regexp("[0-9]{9}");
    if (!regex_match(cpf, regexp)) return 0;
    return 1;
}

int validaNome (string nome)
{
    int len = nome.length();
    if (len<5 || len>20) return 0;
    return 1;
}

int validaData (string data)
{
    regex regexp("(([0-1][0-9]|2[0-8])02|([0-2][0-9]|31)(01|03|05|07|08|10|12)|([0-2][0-9]|30)(04|06|09|11))[0-9]{4}");
    if (!regex_match(data, regexp)) return 0;
    return 1;
}

#endif // VALIDADOR_H