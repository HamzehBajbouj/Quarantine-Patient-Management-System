#ifndef EMERGANCYROOM_H
#define EMERGANCYROOM_H
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Workers.h"
#include "Infected.h"
#include "HospitalRooms.h"


using namespace std;

class EmergancyRoom :  public HospitalRooms
{
private:
int TotalMechanicalVentilation ;
int MechanicalVentilationUnderUse ;
int MechanicalVentilationAvailabe;
bool MechanicalVentilationAvailability;
 //this method for internl use
  void  CalculateBedsAvailable ();
  void  CalculateMechanicalVentilationAvailabeAndUnderuse ();
public:
    EmergancyRoom();
    ~EmergancyRoom();


  void  DisplaySummary() ;
  void  setTotalMechanicalVentilation (int ) ;
  
  int  getTotalMechanicalVentilation() ;
  int  getMechanicalVentilationUnderUse () ;
  int  getMechanicalVentilationAvailabe();

 
  
  //this method is for the beds
  bool  getCapacityStatus( ) ;
  
  
  //these two methods are for the Mechanical Ventilations
  bool getMechanicalVentilationAvailability();
  void setMechanicalVentilationAvailability(bool);
  

};

#endif // EMERGANCYROOM_H
