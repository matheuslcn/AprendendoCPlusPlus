#include <iostream>
#include "Clinic.h"

using namespace std;

int main()
{
    Clinic c;
    cout << c.getTotalPatients() << endl;
    c.addPatient("999", "matheus", "02061995");
    c.addPatient("123", "matheus", "02061955");
    c.addPatient("456", "matheus", "02061995");
    c.addPatient("556", "matheus", "02061995");
    c.addPatient("656", "matheus", "02061995");
    c.addPatient("756", "matheus", "02061995");
    c.addPatient("856", "matheus", "02061995");
    c.addPatient("056", "matheus", "02061995");
    c.remPatient("056");


    c.showPatients();
    return 0;
}
