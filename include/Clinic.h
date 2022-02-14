#include "Patient.h"
#include "Schedule.h"
#include <string>

#ifndef CLINIC_H
#define CLINIC_H


class Clinic
{
    public:
        Clinic();
        int getTotalPatients(void) {return total_patients;};
        int addPatient(string, string, string);
        int remPatient(string);
        void showPatients();

    private:
        Patient *patient_list = NULL;
        Schedule *schedule_list = NULL;
        int total_patients;
        int total_schedules;
};

Clinic::Clinic()
{
    total_patients = 0;
    total_schedules = 0;
}

int Clinic::addPatient(string cpf_, string name_, string bday_)
{
    if (Clinic::total_patients >= 50) return -1; // Colocar um limite no numero de pacientes cadastrados
    Patient *new_patient = new Patient(cpf_, name_, bday_);
    if (!Clinic::patient_list) Clinic::patient_list = new_patient;
    else
    {
        Patient *aux = Clinic::patient_list;
        int cpf1 = stoi(cpf_);
        int cpf2 = stoi(Clinic::patient_list->getCpf());
        if (cpf1 == cpf2) return 0; // Garantir que dois cpfs iguais nao sejam cadastrados
        // SO ADICIONA NO INICIO DA LISTA
        // DEPOIS FAZER UM ISERTION SORT
        Clinic::patient_list = new_patient;
        new_patient->next = aux;
    }
    Clinic::total_patients++;
    return 1; // Cadastrou o novo paciente
}

int Clinic::remPatient (string cpf_)
{
    Patient *aux = Clinic::patient_list;
    Patient *prev = NULL;
    while(aux)
    {
        if (!cpf_.compare(aux->getCpf()))
        {
            if (prev) prev->next = aux->next;
            else Clinic::patient_list = aux->next;
            free(aux);
            Clinic::total_patients--;
            return 1;
        }
        prev = aux;
        aux = aux->next;
    }
    return 0;
}

void Clinic::showPatients()
{
    Patient *aux = Clinic::patient_list;
    while(aux)
    {
        cout << "cpf: " << aux->getCpf() << ", name: " << aux->getName() << ", bday: " << aux->getBDay() << endl;
        aux = aux->next;
    }
}
#endif // CLINIC_H
