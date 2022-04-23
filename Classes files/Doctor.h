#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include <iostream>
#include "Infected.h"
#include "Workers.h"
using namespace std;

class Doctor : public Workers
{
private :
string Specialization;

public:
    Doctor(string ="Null");
    ~Doctor();

 void setSpecialization (string );
 string getSpecialization () ;

 void DisplayWorkerInfo();
 //based on the idea of the patients it will search and edit
 void EditPatientInforamtion(string) ;

 void changePatients(Infected * , string, string) ;
};

#endif // DOCTOR_H
