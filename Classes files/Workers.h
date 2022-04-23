#ifndef WORKERS_H
#define WORKERS_H
#include <string>
#include <iostream>
#include "Infected.h"
using namespace std;

struct test{
    int hnae;
    double gfdd;
    
    };

class Workers
{
    
protected:
    string WorkerID;
    string WorkerName;
    string WorkerPhoneNumber;
    string WorkingRoom ;
    int YearsOfExperience;
    int  IndexCount;
    Infected * PatientsUnderSuperviosion [7];
    void IndexCounter() ;
public:
    Workers(string ="Null",string ="Null",string ="Null",string ="Null",int =0, Infected * =nullptr);
    ~Workers();
    
 
    string getWorkerID () const;
    void setWorkerID (string) ;

    void setWorkerName (string);
    string getWorkerName () const ;
    
    void setWorkerPhoneNumber (string );
    string getWorkerPhoneNumber () const;
    

    void setYearsOfExperience (int);
    int getYearsOfExperience () const;

    void setWorkingRoom (string );
    string getWorkingRoom ()  const;
    
    //this method will connect the classes
    void matchclass(Infected *);
    //this method will return the address for the infected objects based on the ID of the patients
   Infected * ReturnPatientObjectAddress (string) ;
    
    //this one will be redefined later so it can show the year experience
    void virtual DisplayWorkerInfo();
  

   void DisplaySummaryAboutPatients() ;
   
   //the ID of the specfic patient will be bassed to the method.
   void  DisplaySpecificPatientInfo(string);

    bool CheckPateintID (string);
    
    void ShowPatientsUnderSuperviosion();
    
    void show_symptoms_for_patient(string);

    //this method is to write in the file the Patients' IDs.
    string writepatintsID(int i)
    {
      
        return PatientsUnderSuperviosion[i]->getPatientID();

    }
    
    int returnIndexcounter()
    {
         IndexCounter() ;
         return IndexCount;
    }
};

#endif // WORKERS_H
