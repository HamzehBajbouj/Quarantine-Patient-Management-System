#include "Workers.h"
#include <string>
#include <iostream>
#include "Infected.h"
using namespace std;




    
Workers::Workers(string ID,string workername,string phoneNumber,string Room,int YofExper, Infected *coonect)
{
    WorkerID =ID;
    WorkerName =workername;
    WorkerPhoneNumber=phoneNumber;
    WorkingRoom =Room; 
    YearsOfExperience =YofExper;
    PatientsUnderSuperviosion [0]=coonect;
    for (int i = 1 ; i < 7 ; i++)
    PatientsUnderSuperviosion[i]=nullptr;
    IndexCount =7;
}

Workers::~Workers()
{
}



    string Workers::getWorkerID () const
        {return WorkerID;}
        
    void Workers::setWorkerID (string idP)
        {WorkerID=idP;}

    void Workers::setWorkerName (string name)
        { WorkerName =name;}
    
    string Workers::getWorkerName () const 
        {return WorkerName;}
    
    void Workers::setWorkerPhoneNumber (string phNUM)
        {WorkerPhoneNumber = phNUM;}
    
    string Workers::getWorkerPhoneNumber () const
        {return WorkerPhoneNumber;}
    

    void Workers::setYearsOfExperience (int x)
        { YearsOfExperience =x;}
    
    int Workers::getYearsOfExperience () const
        {return YearsOfExperience;}

    void Workers::setWorkingRoom (string Room)
        {WorkingRoom = Room;}
    
    string Workers::getWorkingRoom ()  const
        {return WorkingRoom ;}
    
    
    //this method will connect the classes
    //there will be in the main program some conditions that will tell the user which patients you want to be under the supervion 
    //of the dr by his ID then there should be some mechansime that can find the patient ID and return his address
    void Workers::matchclass(Infected *connect)
        {
            
             for (int i = 0; i < 7 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (PatientsUnderSuperviosion[i]==connect)
                    {
                      cout << "The patient is Already Under the supervision of the worker."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (PatientsUnderSuperviosion[i]==nullptr)
                        {
                           PatientsUnderSuperviosion[i]=connect;
                            break;
                        }
                    
                        
                        
                    }
                    //will check if exceed the number of patients allowed to each doctor
                    bool exceed=false;
                    
                    for (int i = 0 ; i <7 ; i++)
                      {  if ((PatientsUnderSuperviosion[i]==connect)&&(PatientsUnderSuperviosion[i]!=nullptr))
                            exceed=true;
                            
                      }
              

           if (exceed==false)
              { cout<<"you exceed the limit of the Patient for ecah worker"<<endl;}
              
         
              
            }
            
    //this method will return the address for the infected objects based on the ID of the patients
   Infected * Workers::ReturnPatientObjectAddress (string idP) 
   {
       bool check =false;
       IndexCounter();
       for (int i = 0 ; i < IndexCount ; i++)
       {
           if (PatientsUnderSuperviosion[i]->getPatientID()== idP)
           {    check = true;
               return PatientsUnderSuperviosion[i];
            }
       }
    
    if (check==false)
        {   cout <<"No matching ID....."<<endl;
            return nullptr;}
    }
 
    
    //this one will be redefined later so it can show the year experience
    void  Workers::DisplayWorkerInfo()
    {
   
        cout <<"Name :: "<<WorkerName<<"\t"<<"ID :: "<<WorkerID<<endl;
        cout <<"PhoneNumber :: "<<WorkerPhoneNumber<<"\t"<<"Working Room :: "<<WorkingRoom<<endl;
        cout <<"Years of Experience :: "<<YearsOfExperience<<endl;

    }


   void Workers::DisplaySummaryAboutPatients()
   {
            IndexCounter() ;
          /*  int numofpatient=0;
        for (int i =0 ; i < IndexCount ; i ++)
        {
            if (PatientsUnderSuperviosion[i]!=nullptr)
                numofpatient+=1;
        }
        */
        int highDa=0,modDa=0,LowDa=0;
        for (int i = 0 ; i < IndexCount ; i++)
        {
            if (PatientsUnderSuperviosion[i]->getPatientConditon() =="High")
                highDa+=1;
            else if (PatientsUnderSuperviosion[i]->getPatientConditon() =="Moderate")
                modDa+=1;
            else if (PatientsUnderSuperviosion[i]->getPatientConditon() =="Low")
                LowDa+=1;
        }
        
        cout << "You Have ["<<IndexCount << "] Patient undersupervision "<<endl;
        cout <<":: Their conditions are ::"<<endl;
            cout <<"["<<highDa<<"] is High Condition"<<endl;
            cout <<"["<<modDa<<"] is Moderate Condition"<<endl;
            cout <<"["<<LowDa<<"] is Low Condition"<<endl;
    }
   
   
   //the ID of the specfic patient will be bassed to the method.
   void  Workers::DisplaySpecificPatientInfo(string idp)
   {
     IndexCounter() ;
       bool check ;
    for (int i = 0 ; i < IndexCount ; i++)
       {
           string tem=PatientsUnderSuperviosion[i]->getPatientID();
           if (tem== idp)
            {    check =true;
               PatientsUnderSuperviosion[i]->DisplayaSpcificInfo();
                break;
            }
            else 
            {
                check=false;
                }
            
        }
        
        if (check==false)
            {
                cout<<"There is no Match for the ID..."<<endl;
            }
            
       
   }
   
 void Workers::IndexCounter() 
 {
     int tempnum=0;
              for (int i = 0 ; i <7 ; i++)
              {
                  if (PatientsUnderSuperviosion[i]==nullptr)
                      tempnum++;
              }
                 
                IndexCount=7-tempnum;
     
     
     }

 bool Workers::CheckPateintID (string idx)
 {
     IndexCounter();
     
     for (int i = 0 ; i < IndexCount ; i++)
     {
         if (PatientsUnderSuperviosion[i]->getPatientID()==idx)
                return true;
    }
     
   
  return false;}
 
 void Workers::ShowPatientsUnderSuperviosion ()
 {
     IndexCounter();
     cout <<"<<< There are ["<<IndexCount<<"] UnderSuperviosion >>>"<<endl;
     cout <<"::: The Patients'ID are :::"<<endl;
     cout <<"--------------------"<<endl;
     for (int i =0 ; i < IndexCount ; i++)
     {
         cout <<"ID for the ["<<i+1<<"] patient is :: "<<PatientsUnderSuperviosion[i]->getPatientID()<<endl;
         
    }
     cout <<"--------------------"<<endl;
}


void Workers::show_symptoms_for_patient(string idp)
{
     IndexCounter();
     int indexp;
     bool check2=false;
    for (int i=0 ; i < IndexCount ; i++)
    {
        if (PatientsUnderSuperviosion[i]->getPatientID()==idp)
        {   indexp=i;
            check2=true;
            break;
            
        }  
    }
    
    if (check2==true)
    {
        PatientsUnderSuperviosion[indexp]->showAllSymptoms();
    }
    else
    {
        cout <<"There is not Matching ID ...."<<endl;
    }
    
}