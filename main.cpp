#include <iostream>
#include "class/Clinica.h"
#include "class/Validador.h"

using namespace std;

int main()
{
    Clinica *c = new Clinica();
    int v;

    for (int i=0; i<10; i++)
    {
        string cpf, nome, data;
        cout << "Digite o CPF do paciente " << i+1 << ": ";
        cin >> cpf;
        cout << v << endl;
        cout << "Digite o nome do paciente " << i+1 << ": ";
        cin >> nome;
        cout << "Digite o aniversario do paciente " << i+1 << ": ";
        cin >> data;
        v = c->addPaciente(cpf, nome, data);
        if (!v) cout << "Paciente ja cadastrado" << endl;
        if (v<0) cout << "Quantidade de pacientes maxima ja atingida" << endl;
        if (v>0) cout << "Paciente cadastrado com sucesso" << endl;

        
    }

    c->mostraPacientes();
    return 0;
}
