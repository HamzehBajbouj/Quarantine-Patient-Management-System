#include "HospitalRooms.h"
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Workers.h"
#include "Infected.h"

using namespace std;

HospitalRooms::HospitalRooms()
{
    BedsNumber=70;
    AvailabeBeds=0;
    IndexCountPa=70;
    IndexCountNu=10;
    IndexCountDo=10;

    
    for (int i = 0 ; i < 70 ; i ++)
        {infected_patients [i]=nullptr;}
        
    for (int i = 0 ; i < 10 ; i ++)
        {ResponsibleDoctors [i]=nullptr;}
    
     for (int i = 0 ; i < 10 ; i ++)
        {ResponsibleNurses [i]=nullptr;}
    CapacityStatus = true;
}

HospitalRooms::~HospitalRooms()
{
}

    
    void HospitalRooms::setBedsNumber(int num)
        {BedsNumber=num;}
    void HospitalRooms::setAvailabeBeds(int num)
        {AvailabeBeds=num;}
    void HospitalRooms::setCapacityStatus(bool value)
        {CapacityStatus=value;}
    
    
    
    int HospitalRooms::getBedsNumber()
        {return BedsNumber;}
    int HospitalRooms::getAvailabeBeds()
        {return AvailabeBeds;}
    bool HospitalRooms::getCapacityStatus()
        {return CapacityStatus;}

    void HospitalRooms::MatchClasses(Workers *connect) 
    {
        
         for (int i = 0; i < 10 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (ResponsibleNurses [i]==connect)
                    {
                      cout << "The Nurse is aleady working in the room."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (ResponsibleNurses [i]==nullptr)
                        {
                           ResponsibleNurses [i]=connect;
                            break;
                        }
                    
                        
                        
                    }
                    //will check if exceed the number of patients allowed to each student
                    bool exceed=false;
                    
                    for (int i = 0 ; i <10 ; i++)
                      {  if ((ResponsibleNurses [i]==connect)&&(ResponsibleNurses [i]!=nullptr))
                            exceed=true;
                            
                      }
              

           if (exceed==false)
              { cout<<"you exceed the limit of the Nurses in The room"<<endl;}
              
         
        
        }
        
    void HospitalRooms::MatchClasses(Doctor *connect)
    {
        for (int i = 0; i < 10 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (ResponsibleDoctors [i]==connect)
                    {
                      cout << "The Doctor is aleady working in the room."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (ResponsibleDoctors [i]==nullptr)
                        {
                          ResponsibleDoctors [i]=connect;
                            break;
                        }
                    
                        
                        
                    }
                    //will check if exceed the number of patients allowed to each student
                    bool exceed=false;
                    
                    for (int i = 0 ; i <10 ; i++)
                      {  if ((ResponsibleDoctors [i]==connect)&&(ResponsibleDoctors [i]!=nullptr))
                            exceed=true;
                            
                      }
              

           if (exceed==false)
              { cout<<"you exceed the limit of the Doctors in The room"<<endl;}
              
        }
    
    
    void HospitalRooms::MatchClasses(Infected *connect)
    {
           for (int i = 0; i < 70 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (infected_patients [i]==connect)
                    {
                      cout << "The patient is already in the room."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (infected_patients [i]==nullptr)
                        {
                          infected_patients [i]=connect;
                            break;
                        }
                    
                        
                        
                    }
                    //will check if exceed the number of patients 
                    bool exceed=false;
                    
                    for (int i = 0 ; i <70 ; i++)
                      {  if ((infected_patients [i]==connect)&&(infected_patients [i]!=nullptr))
                            exceed=true;
                            
                      }
              

           if (exceed==false)
              { cout<<"you exceed the limit of the pateints in The room"<<endl;}
              
        
        }
void HospitalRooms::IndexCounter ()
    {
   


 
        int tempnum=0;
              for (int i = 0 ; i <10 ; i++)
              {
                  if (ResponsibleNurses [i]==nullptr)
                      tempnum++;
              }
                 
                IndexCountNu=10-tempnum;
                
        int tempnum1=0;
              for (int i = 0 ; i <10 ; i++)
              {
                  if (ResponsibleDoctors [i]==nullptr)
                      tempnum1++;
              }
                 IndexCountDo=10-tempnum1; 
         
         
        int tempnum2=0;
            for (int i = 0 ; i <70 ; i++)
              {
                  if (infected_patients[i]==nullptr)
                      tempnum2++;
              }
                 IndexCountPa=70-tempnum2; 
      
        }