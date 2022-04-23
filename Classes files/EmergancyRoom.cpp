#include "EmergancyRoom.h"
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Workers.h"
#include "Infected.h"
#include "HospitalRooms.h"


using namespace std;
EmergancyRoom::EmergancyRoom()
{
    
     TotalMechanicalVentilation =70;
     MechanicalVentilationUnderUse=0 ;
     MechanicalVentilationAvailabe=70;
     MechanicalVentilationAvailability = true;
}

EmergancyRoom::~EmergancyRoom()
{
}

  void  EmergancyRoom::DisplaySummary()
  {
      IndexCounter ();
      CalculateBedsAvailable ();
    CalculateMechanicalVentilationAvailabeAndUnderuse ();
    
        string Capacity;
        
        if (CapacityStatus==false)
        {
            Capacity="Full"; 
        }
        else 
            {Capacity = "Not Full";}
            
        string MechanicalVentilationCapacity;
        
         if (MechanicalVentilationAvailability==false)
        {
            MechanicalVentilationCapacity="Unavailable"; 
        }
        else 
            {MechanicalVentilationCapacity = "Available";}
        
            
        cout << "The Emergancy Room has ["<<IndexCountPa<<"] patients in it."<<endl;
        cout <<"There are ["<<IndexCountDo<<"] Doctors Working in this Room."<<endl;
        cout <<"There are ["<<IndexCountNu<<"] Nurses Working in this Room."<<endl;
        cout <<"The total Beds is ["<<BedsNumber<<"]."<<endl;
        cout <<"Number of Beds Available ["<<AvailabeBeds<<"]."<<endl;
        cout <<"The Beds Capacity Status is ::"<<Capacity<<endl;
        cout <<"Total Number of Mechanical Ventilations ["<<TotalMechanicalVentilation<<"]."<<endl;
        cout <<"Number of Mechanical Ventilations under using ["<<MechanicalVentilationUnderUse<<"]."<<endl;
        cout << "Number of Mechanical Ventilations Available ["<<MechanicalVentilationAvailabe<<"]."<<endl;
        cout <<"Mechanical Ventilation machines Availability ["<<MechanicalVentilationCapacity<<"]."<<endl;
     
      }
  
  
  
  void  EmergancyRoom::setTotalMechanicalVentilation (int x) 
  {TotalMechanicalVentilation=x;}
  

  
  
  
  int  EmergancyRoom::getTotalMechanicalVentilation()
  {
      CalculateMechanicalVentilationAvailabeAndUnderuse ();
      return TotalMechanicalVentilation;
  }
  
  int  EmergancyRoom::getMechanicalVentilationUnderUse ()
  {
      CalculateMechanicalVentilationAvailabeAndUnderuse ();
      return MechanicalVentilationUnderUse;
  }
  
  int EmergancyRoom::getMechanicalVentilationAvailabe()
  {
       CalculateMechanicalVentilationAvailabeAndUnderuse ();
       return MechanicalVentilationAvailabe;
    }

 
 //note that here the Capacity is only for the beds
  bool  EmergancyRoom::getCapacityStatus( )
  {
         CalculateBedsAvailable ();
    
            return CapacityStatus;
      }
  
  
  

bool EmergancyRoom::getMechanicalVentilationAvailability()
{
    CalculateMechanicalVentilationAvailabeAndUnderuse ();
    return MechanicalVentilationAvailability;
}

  void EmergancyRoom::setMechanicalVentilationAvailability(bool value)
  {
      
      MechanicalVentilationAvailability=value;
  }
  
    void  EmergancyRoom::CalculateMechanicalVentilationAvailabeAndUnderuse ()
  {
       IndexCounter ();
       MechanicalVentilationUnderUse=IndexCountPa;
         MechanicalVentilationAvailabe=TotalMechanicalVentilation-IndexCountPa;
         if (MechanicalVentilationAvailabe==0)
             MechanicalVentilationAvailability=false;
    }
    
    
   void EmergancyRoom::CalculateBedsAvailable ()
 {
     IndexCounter ();
     
     AvailabeBeds = BedsNumber-IndexCountPa;
     if (AvailabeBeds==0)
         CapacityStatus=false;
}
