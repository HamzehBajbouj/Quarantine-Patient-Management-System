#include "PatientInformation.h"
#include <iostream>
#include <string>
using namespace std;


PatientInformation::PatientInformation(string patientN, string patientNum, string patientAdd)
{
    patientName=patientN;
    patientPhoneNumber=patientNum;
    patientAddress=patientAdd;
}

PatientInformation::~PatientInformation()
{
}

string PatientInformation::getpatientName() const
                {return patientName;}


string PatientInformation::getpatientPhoneNumber() const
                {return patientPhoneNumber;}

string PatientInformation::getpatientAddress()  const
                {return patientAddress;}

  
  
void PatientInformation::setpatientName(string name)
                {patientName= name;}
  
void PatientInformation::setpatientPhoneNumber(string PhoneNum)
                {patientPhoneNumber= PhoneNum;}
  
void PatientInformation::setpatientAddress(string Address)
                {patientAddress= Address;}  
    
 ostream &operator<<(ostream & output ,const PatientInformation  & object)
 {
     output<<"The patient's Name ::"<<object.patientName<<endl;
     output<<"The patient's PhoneNumber ::"<<object.patientPhoneNumber<<endl;
     output<<"The patient's Address ::"<<object.patientAddress<<endl;
     return output;
}
 

 
 istream &operator>>(istream &input ,PatientInformation  &object )
 {
     cout<<"Enter Patient's Name ::";
     getline(input,object.patientName);
     
     cout<<"Enter Patient's PhoneNumber ::";
     getline(input,object.patientPhoneNumber);
     
    cout<<"Enter Patient's Address ::";
    getline(input,object.patientAddress);
    
    
    return input; 
}