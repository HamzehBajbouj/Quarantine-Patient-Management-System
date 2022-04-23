#include "Patient.h"
#include <iostream>
#include <string>
#include "PatientInformation.h"
using namespace std;

Patient::Patient() 
{
    for (int i = 0; i < 7 ; i ++)
        {symptoms[i]="Null";}
    PatientID ="Null";
    CurrentRoom="Null";
    PatientStatus=false;
}


Patient::~Patient()
{
}




bool Patient::getPatientStatus() const
    {return PatientStatus;}
    
void  Patient::setPatientStatus (bool status)
        {PatientStatus=status;}

void Patient::setAllPatientInfoByPassing (string name, string PhoneNumber,string Address )
    {
        patientInfo.setpatientName(name);
        patientInfo.setpatientPhoneNumber(PhoneNumber);
        patientInfo.setpatientAddress(Address);
    }
    
    
    

   
 //here there will be local variables that will be passed to the patient object also it's a list
void Patient:: EditPatientInfo() 
        {
            
        cout<<"To Edit the patient's perosnal Infomration Choose the Number you want\n\n";
            int chosenNum=4345;
            string insertedInformation;
            cout<<"0- Display the Patient Information"<<endl;
            cout <<"1- Patient Name"<<endl;
            cout <<"2- Patient Phone Number"<<endl;
            cout <<"3- Patient Address"<<endl;
            cout <<"4- Exit"<<endl;
            
            for (; chosenNum!=4 ; )
            {
                cout<<"Enter a Number :: ";
                cin>>chosenNum;
                cin.ignore();
                if (chosenNum==0)
                    {cout<<patientInfo;}
                
                else if (chosenNum==1)
                {
                    cout<<"Enter the New Name :: ";
                        getline(cin,insertedInformation);
                    patientInfo.setpatientName(insertedInformation);
                }
                
                else if (chosenNum==2)
                {
                    cout<<"Enter the New Phone Number :: ";
                        getline(cin,insertedInformation);
                    patientInfo.setpatientPhoneNumber(insertedInformation);
                }
                
                else if (chosenNum==3)
                 {
                    cout<<"Enter the New Address :: ";
                        getline(cin,insertedInformation);
                    patientInfo.setpatientAddress(insertedInformation);
                }
                else
                {break;}
              
            }
        }




//by using the cout << operator.
void Patient:: DisplayAllPatienInfo() 
{
    //cout <<patientInfo;
     cout<<"The patient's Name :: "<<endl<<patientInfo.getpatientName()<<endl;
     cout<<"The patient's PhoneNumber ::"<<patientInfo.getpatientPhoneNumber()<<endl;
     cout<<"The patient's Address ::"<<patientInfo.getpatientAddress()<<endl;
}



//some conditons and loops
void  Patient:: DisplayaSpcificInfo() 
{
    
     cout<<"To Display a Spcific information Choose the Number you want\n\n";
            int chosenNum;
            string insertedInformation;
            cout<<"0- Display the All Patient Information"<<endl;
            cout <<"1- Patient Name"<<endl;
            cout <<"2- Patient Number"<<endl;
            cout <<"3- Patient Address"<<endl;
            cout <<"4- Exit"<<endl;
            
            for (; chosenNum!=4 ; )
            {
                cout<<"Enter a Number :: ";
                cin>>chosenNum;
                cin.ignore();
                if (chosenNum==0)
                    {cout<<patientInfo;}
                
                else if (chosenNum==1)
                {
                  cout<<patientInfo.getpatientName()<<endl;
                }
                
                else if (chosenNum==2)
                {
                   cout<<patientInfo.getpatientPhoneNumber()<<endl;
                }
                
                else if (chosenNum==3)
                 {
                  cout<<patientInfo.getpatientAddress()<<endl;
                }
                else
                {break;}
              
            }
    }
    


void Patient::setPatientID (string ID)
    {PatientID=ID;}

string Patient::getPatientID () const
    {return PatientID;}

//these methods is for CurrentRoom variable
void Patient::setCurrentRoom (string CR)
    {CurrentRoom=CR;}


string Patient::getCurrentRoom() const
        {return CurrentRoom;}


void Patient::SetSymptoms(int i, string Sym)
    {
        if (i > 6)
            cout <<"You Excced the index, enter a number less than 7"<<endl;
        else
        symptoms[i]=Sym;
    }


string Patient::GetSymptoms(int i)
    {    if (i > 6)
            {cout <<"You Excced the index"<<endl; 
            return symptoms[0];}
        
        return  symptoms[i];}

string Patient::getpatientname()
{ return patientInfo.getpatientName();}

string Patient::getpatientphonenumber()
{ return patientInfo.getpatientPhoneNumber();}

string Patient::getpatientaddress()
{return patientInfo.getpatientAddress();}