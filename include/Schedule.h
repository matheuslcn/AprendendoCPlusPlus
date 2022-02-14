#include <string>

#ifndef SCHEDULE_H
#define SCHEDULE_H

using namespace std;

class Schedule
{
    public:
        Schedule();

    private:
        string patient_cpf;
        string date;
        string begin_time;
        string end_time;
};

#endif // SCHEDULE_H
