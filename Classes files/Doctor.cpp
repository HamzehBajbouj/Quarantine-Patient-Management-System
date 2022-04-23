#include "Doctor.h"
#include <string>
#include <iostream>
#include "Infected.h"
#include "Workers.h"
using namespace std;

Doctor::Doctor(string specialization)
{
    Specialization=specialization;
}

Doctor::~Doctor()
{
}

 void Doctor::setSpecialization (string spe)
    { Specialization=spe; }
 
 string Doctor::getSpecialization ()
    {return Specialization;}

 void Doctor::DisplayWorkerInfo()
 {
       cout <<"Name :: "<<WorkerName<<"\t"<<"ID :: "<<WorkerID<<endl;
        cout <<"PhoneNumber :: "<<WorkerPhoneNumber<<"\t"<<"Working Room :: "<<WorkingRoom<<endl;
        cout <<"Years of Experience :: "<<YearsOfExperience<<"\t"<<"Specialization :: "<<Specialization<<endl;
     
}

 //based on the idea of the patients it will search and edit
 void Doctor::EditPatientInforamtion(string idp)
 {
     
       IndexCounter();
     
     
     bool check = false;
        
     int num =434;
     string store;
     for (int i = 0 ; i < IndexCount ; i ++)
     {
          
         for (int i = 0 ; i < IndexCount ; i++)
       {
           if (PatientsUnderSuperviosion[i]->getPatientID()== idp)
            {   check =true;}
       }
       
       if (check==false)
           {cout<<"There is No matched ID"<<endl;
            break;}
            
       if (check==true)
       {   
           cout << "To Edit the Inforamtion for ["<<PatientsUnderSuperviosion[i]->getpatientname()<<"]"<<endl;
        
        
       cout<<"1- To Edit The Condition"<<endl;
       cout<<"2- Exist "<<endl;
       
         for (;num !=2 ;)
        {
            cout <<"Please Enter A number :: ";
            cin >> num;
            cin.ignore();
            if (num==1)
                    {cout <<"Insert The Condition {High,Moderate,Low}::";
                        getline(cin,store);
                        PatientsUnderSuperviosion[i]->setPatientConditon(store);
                    }             
                    
                else 
                    {break;}
         
        }
     
     break;
     }
        }
 }  

 