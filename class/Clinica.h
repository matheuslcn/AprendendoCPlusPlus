#include "Paciente.h"
#include "Agendamento.h"
#include <string>
#include <map>

#ifndef CLINICA_H
#define CLINICA_H


class Clinica
{
    public:
        Clinica();
        int addPaciente(string, string, string);
        int remPaciente(string);
        int addAgendamento(string, string, string);
        int remAgendamento(string);
        void mostraPacientes();
        void mostraAgendamentos();

    private:
        std::map<string, Paciente*> listaDePacientes;
        std::map<string, Agendamento*> listaDeAgendamentos;
};

Clinica::Clinica()
{

}

int Clinica::addPaciente(string cpf, string nome, string niver)
{
    if (listaDePacientes.size() >= 50) return -1; // Colocar um limite no numero de pacientes cadastrados
    if (listaDePacientes[cpf]) return 0; // Impedir q cadastre um novo cpf igual
    Paciente *novoPaciente = new Paciente(cpf, nome, niver);
    listaDePacientes[cpf] = novoPaciente;
    return 1; // Cadastrou o novo paciente
}

int Clinica::remPaciente(string cpf)
{
    map<string, Paciente*>::iterator it = listaDePacientes.find(cpf);
    if (it == listaDePacientes.end()) return 0;
    listaDePacientes.erase(it->first);
    return 1;
}


int Clinica::addAgendamento(string cpf, string data, string hora)
{
    if (listaDeAgendamentos.size() >= 100) return -1; // Colocar um limite no numero de pacientes cadastrados
    if (listaDeAgendamentos[cpf]) return 0; // Impedir q cadastre um novo cpf igual
    Agendamento *novoAgendamento = new Agendamento(cpf, data, hora);
    listaDeAgendamentos[cpf] = novoAgendamento;
    return 1;
}

int Clinica::remAgendamento(string cpf)
{
    map<string, Agendamento*>::iterator it = listaDeAgendamentos.find(cpf);
    if (it == listaDeAgendamentos.end()) return 0;
    listaDeAgendamentos.erase(it->first);
    return 1;
}


void Clinica::mostraPacientes()
{
    for (map<string, Paciente*>::iterator it = listaDePacientes.begin(); it != listaDePacientes.end(); it++)
    {
        Paciente *p = it->second;
        cout << "CPF: " << p->pegaCpf() << "\nNome: " << p->pegaNome() << "\nBday: " << p->pegaNiver() << endl << endl;
    }
}

void Clinica::mostraAgendamentos()
{
    for (map<string, Agendamento*>::iterator it = listaDeAgendamentos.begin(); it!=listaDeAgendamentos.end(); it++)
    {
        Agendamento *p = it->second;
        cout << "CPF: " << p->pegaCpfPaciente() << "\nHorario: " << p->pegaDataHoraDeInicio() << endl << endl;

    }
}


#endif // CLINICA_H
