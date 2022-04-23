#ifndef QUARATINEROOM_H
#define QUARATINEROOM_H
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Workers.h"
#include "Infected.h"
#include "HospitalRooms.h"
#include  <stdlib.h> 

using namespace std;


struct QuDetails{
   // int numerOfDaysSpent; //three days at most
    string StartingDate ;
    string  ExitingDate ;
    string PatientID;
    
    }; 
    
    
class QuaratineRoom : public HospitalRooms
{
private:


QuDetails RoomResidents [70];
int calcualteDayspent(string ,string );
public:
    QuaratineRoom();
    ~QuaratineRoom();
    
 void SetRoomResidentsbyPassing(int, string,string ,string);
 
 void setid(string idf)
 {
     for (int i=0; i <70;i++ )
     {
         if (RoomResidents[i].PatientID!="Null")
         {
             RoomResidents[i].PatientID=idf;
             break;
        }
         
    }
     
}
 void DisplaySummary();
 void EditQuDetailsForPatient (string );
 void CalculateBedsAvailable () ;
    string getRoomResidents(int i)
    {
        internalser();
        return RoomResidents[i].PatientID+","+RoomResidents[i].StartingDate+","+RoomResidents[i].ExitingDate;
    }
    
    int getTotalnumerOfDaysSpent () ;
    
    int getNumberOfDaysSpentForspecificID(string );
    string getStartingDateByID (string) ;
    string getExitingDateByID  (string) ;
    
    void setStartingDateByID (string,string ) ;
    void setExitingDateByID  (string,string) ;
    
    bool  getCapacityStatus();

    //this method is needed when we change the ID of any patient in the orginal object
    void setIDforRoomRsidents(string , string) ;
    //this method is needed when we change the room of a patient
    //after we apply this we will use the method to pass the index to  SetRoomResidentsbyPassing and set all the data to Null
    //
   int getPatientIDindex(int ,string) ;
   
   
   
     void internalser()
    {
        IndexCounter ();
        for (int i = 0 ; i < IndexCountPa ; i++)
        {
            RoomResidents[i].PatientID=infected_patients[i]->getPatientID();
            
        }
        
        
    }
   
};

#endif // QUARATINEROOM_H
