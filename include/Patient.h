#include <string>

#ifndef PATIENT_H
#define PATIENT_H

using namespace std;

class Patient
{
    public:
        Patient *next = NULL;
        Patient(string, string, string);
        string getCpf(void){return cpf;};
        string getName(void){return name;};
        string getBDay(void) {return bday;};


    private:
        string cpf;
        string name;
        string bday;

};

Patient::Patient(string cpf_, string name_, string bday_)
{
    cpf = cpf_;
    name = name_;
    bday = bday_;
}


#endif // PATIENT_H
