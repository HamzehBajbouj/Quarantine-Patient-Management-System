#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include "PatientInformation.h"
using namespace std;

class Patient
{
    
protected:

 PatientInformation patientInfo;
 bool PatientStatus;
 string symptoms [7];
 string PatientID;
 string CurrentRoom;
public:
    Patient() ;
    ~Patient();
    
bool getPatientStatus() const;
void setPatientStatus (bool );


//this method will be inhrited to the infected class and it will use the cin >> operator to display the infromation of the patinet
void   virtual setAllPatientInfo () =0;
//this method will be useful when we read from the files
void setAllPatientInfoByPassing(string ,string ,string) ;

 //here there will be local variables that will be passed to the patient object also it's a list
void EditPatientInfo() ;

//by using the cout << operator.
void DisplayAllPatienInfo ();
//some conditons and loops
void virtual DisplayaSpcificInfo() ;

void setPatientID (string );
string getPatientID () const;

//these methods is for CurrentRoom variable
void setCurrentRoom (string);
string getCurrentRoom() const;

//
void SetSymptoms(int , string ) ;
string GetSymptoms(int);

string getpatientname();
string getpatientphonenumber();
string getpatientaddress();
};

#endif // PATIENT_H

