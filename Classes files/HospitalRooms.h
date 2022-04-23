#ifndef HOSPITALROOMS_H
#define HOSPITALROOMS_H
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Workers.h"
#include "Infected.h"

using namespace std;

class HospitalRooms
{
protected:


int BedsNumber;
int AvailabeBeds;
int IndexCountNu;
int IndexCountDo;
int IndexCountPa;
Doctor *ResponsibleDoctors[10];
Workers *ResponsibleNurses[10];
Infected *infected_patients [70];

bool CapacityStatus;

void IndexCounter ();

public:
    HospitalRooms();
    ~HospitalRooms();
    
    void setBedsNumber(int );
    void setAvailabeBeds(int);
    void setCapacityStatus(bool) ;
    
    void virtual CalculateBedsAvailable () =0;
    
    int getBedsNumber();
    int getAvailabeBeds();
    bool virtual getCapacityStatus();

    void MatchClasses(Workers *);
    void MatchClasses(Doctor *);
    void MatchClasses(Infected *);



};

#endif // HOSPITALROOMS_H
