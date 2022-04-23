#include "LogInSystem.h"
#include <iostream>
#include <string>
#include "Patient.h"
#include "Infected.h"
#include "Workers.h"
#include "Doctor.h"
#include "QuaratineRoom.h"
#include "EmergancyRoom.h"

using namespace std;

LogInSystem::LogInSystem()
{
    adminID ="Admin";
    
    IndexCountNu=20;
     IndexCountDo=20;
     IndexCountPa=140;
     
     for (int i = 0 ; i < 20 ; i++)
     {
         DoctoresIDs [i]="Null";
         NuresesIDs[i]="Null";
         
    }
    for (int i = 0 ; i <140 ; i++)
        {PateintsIDs[i]="Null";}
}

LogInSystem::~LogInSystem()
{
}

   
    
 void LogInSystem::MatchClasses(Workers *connect)
 {
     
          for (int i = 0; i < 20 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (Nureses [i]==connect)
                    {
                      cout << "The Nurse is aleady working in the System."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (Nureses [i]==nullptr)
                        {
                          Nureses [i]=connect;
                          connectID(Nureses [i]->getWorkerID());
                            break;
                        }
                    
                        
                        
                    }
                    //will check if exceed the number of patients allowed to each student
                    bool exceed=false;
                    
                    for (int i = 0 ; i <20 ; i++)
                      {  if ((Nureses [i]==connect)&&(Nureses [i]!=nullptr))
                            exceed=true;
                            
                      }
              

           if (exceed==false)
              { cout<<"you exceed the limit of array"<<endl;}
     
            connectID (connect->getWorkerID());
     }
     
     void LogInSystem::MatchClasses(Doctor *connect) 
     
     {
         
          for (int i = 0; i < 20 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (doctors [i]==connect)
                    {
                      cout << "The doctor is aleady working in the System."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (doctors [i]==nullptr)
                        {
                          doctors [i]=connect;
                          connectID(doctors [i]->getWorkerID());
                            break;
                        }
                    
                        
                        
                    }
                    //will check if exceed the number of patients allowed to each student
                    bool exceed=false;
                    
                    for (int i = 0 ; i <20 ; i++)
                      {  if ((doctors [i]==connect)&&(doctors [i]!=nullptr))
                            exceed=true;
                            
                      }
              

           if (exceed==false)
              { cout<<"you exceed the limit of array"<<endl;}
       connectID (connect->getWorkerID());
         
    }
    
 void LogInSystem::MatchClasses(Infected *connect)
 {
     
      for (int i = 0; i < 140 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (Patients [i]==connect)
                    {
                      cout << "The patient is aleady working in the Sytem."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (Patients [i]==nullptr)
                        {
                          Patients [i]=connect;
                          connectID(Patients[i]->getPatientID ());
                            break;
                        }
                    
                        
                        
                    }
                    //will check if exceed the number of patients allowed to each student
                    bool exceed=false;
                    
                    for (int i = 0 ; i <140 ; i++)
                      {  if ((Patients [i]==connect)&&(Patients [i]!=nullptr))
                            exceed=true;
                            
                      }
              

           if (exceed==false)
              { cout<<"you exceed the limit of array"<<endl;}
     
       connectID (connect->getPatientID());
     }
     
      bool LogInSystem::checkID (string ID)
      {
          IndexCounter();
          
          if (ID ==adminID)
             { return true;}
             
        for (int i=0; i<IndexCountNu; i++ )
        {   
            if (NuresesIDs[i]==ID)
                return true;
        }
        
         for (int i=0; i<IndexCountDo; i++ )
        {   
            if (DoctoresIDs[i]==ID)
                return true;
        }
        
         for (int i=0; i<IndexCountPa; i++ )
        {   
            if (PateintsIDs[i]==ID)
                return true;
        }
          
          return false;
    }
  
    
     void LogInSystem::IndexCounter()
     {
         
      int tempnum=0;
              for (int i = 0 ; i <20 ; i++)
              {
                  if (Nureses [i]==nullptr)
                      tempnum++;
              }
                 
                IndexCountNu=20-tempnum;
                
        int tempnum1=0;
              for (int i = 0 ; i <20 ; i++)
              {
                  if (doctors[i]==nullptr)
                      tempnum1++;
              }
                 IndexCountDo=20-tempnum1; 
         
         
        int tempnum2=0;
            for (int i = 0 ; i <140 ; i++)
              {
                  if (Patients[i]==nullptr)
                      tempnum2++;
              }
                 IndexCountPa=140-tempnum2; 

   
         }

     
     void LogInSystem::connectID (string ID)
     {
         IndexCounter();
         
         
         
         if (ID.substr(0,1)=="N")
         {
         for (int i = 0 ; i < IndexCountNu+1 ; i++)
         {
         if (ID==NuresesIDs[i])
                 {break;}
            else if (NuresesIDs[i]=="Null")
                {NuresesIDs[i]=ID;
                break;}
             
        }
         }
        
        else if (ID.substr(0,1)=="D")
        {
           for (int i = 0 ; i < IndexCountDo+1 ; i++)
         {
             if (ID==DoctoresIDs[i])
                { break;}
            else if (DoctoresIDs[i]=="Null")
               { DoctoresIDs[i]=ID;
               break;}
             
        }
        }
        
        else if (ID.substr(0,1)=="P")
        {
          for (int i = 0 ; i < IndexCountPa+1 ; i++)
         {
             if (ID==PateintsIDs[i])
                { break;}
            else if (PateintsIDs[i]=="Null")
              {  PateintsIDs[i]=ID;
              break;}
             
        }
        }
         
    }
    
         //void readfromFile(string);