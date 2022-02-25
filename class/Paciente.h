#include <string>

#ifndef PACIENTE_H
#define PACIENTE_H

using namespace std;

class Paciente
{
    public:
        Paciente(string, string, string);
        string pegaCpf(void){return cpf;};
        string pegaNome(void){return nome;};
        string pegaNiver(void) {return niver;};


    private:
        string cpf;
        string nome;
        string niver;

};

Paciente::Paciente(string cpf_, string nome_, string niver_)
{
    cpf = cpf_;
    nome = nome_;
    niver = niver_;
}


#endif // PATIENT_H
