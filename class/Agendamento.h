#include <string>
#include <ctime>

#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

using namespace std;

class Agendamento
{
    public:
        Agendamento(string, string, string);
        string pegaDataHoraDeInicio();
        string pegaDataHoraDeTermino();
        string pegaCpfPaciente(void) {return CpfPaciente;};

    private:
        string CpfPaciente;
        struct tm *dataHoraDeInicio;
        struct tm *converterParaTm(string, string);
};

Agendamento::Agendamento(string cpf, string data_, string horaDeInicio_)
{
    CpfPaciente = cpf;
    dataHoraDeInicio = converterParaTm(data_, horaDeInicio_);
}

struct tm *Agendamento::converterParaTm(string data_, string horaDeInicio_)
{
    struct tm *dataHora = new tm();
    dataHora->tm_mday = (data_[0]-'0')*10 + (data_[1-'0']);
    dataHora->tm_mon = (data_[2]-'0')*10 + (data_[3]-'0');
    dataHora->tm_year = (data_[4]-'0')*1000 + (data_[5]-'0')*100 + (data_[6]-'0')*10 + (data_[7]-'0');
    return dataHora;
}


string Agendamento::pegaDataHoraDeInicio()
{
    int dia = dataHoraDeInicio->tm_mday;
    int hora = dataHoraDeInicio->tm_hour;
    int minuto = dataHoraDeInicio->tm_min;

    return to_string(dia) + " �s " + to_string(hora) + ":" + to_string(minuto);
}

string Agendamento::pegaDataHoraDeTermino()
{
    int dia = dataHoraDeInicio->tm_mday;
    int hora = dataHoraDeInicio->tm_hour;
    int minuto = dataHoraDeInicio->tm_min;

    if (minuto >= 60)
    {
        minuto -= 60;
        hora++;
    }

    return to_string(dia) + " �s " + to_string(hora) + ":" + to_string(minuto);
}


#endif // AGENDAMENTO_H
