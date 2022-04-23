#include "Hospital.h"
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Workers.h"
#include "QuaratineRoom.h"
#include "EmergancyRoom.h"
#include "HospitalInformation.h"
using namespace std;


Hospital::Hospital()
{
     indexDr =20; 
    indexNu =20;
       for (int i = 0 ; i < 20 ; i ++)
        {nurses [i]=nullptr;}
    
     for (int i = 0 ; i < 20 ; i ++)
        {doctors [i]=nullptr;}
}

Hospital::~Hospital()
{
}

    void Hospital::sethopitallocation (string location)
        {HopitalInfo.setHopitalLocation(location);}
    void Hospital::sethospitalname (string name)
       {HopitalInfo.setHospitalName(name);}
    void Hospital::sethopitalcontactnum (string number) 
        {HopitalInfo.setHopitalContactNum(number);}
        
    void Hospital::displayHosptalInformation () 
    {
        cout <<"<<<<<Hospital Informaiton>>>>>"<<endl<<endl;
        
        cout <<"Hospital Name ::"<<HopitalInfo.getHospitalName()<<endl;
        
        cout <<"Hospital Location ::"<<HopitalInfo.getHopitalLocation()<<endl;
        
        cout <<"Hospital Contact Number ::"<<HopitalInfo.getHopitalContactNum()<<endl<<endl;
    }
    
void Hospital::matchDr(Doctor * connect)
{
    for (int i = 0; i < 20 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (doctors [i]==connect)
                    {
                      cout << "The Doctor is aleady working in the room."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (doctors [i]==nullptr)
                        {
                          doctors [i]=connect;
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
              { cout<<"you exceed the limit of the Doctors in The room"<<endl;}
              matchDrwithRooms() ;
    
    } 



void Hospital::matchNurses(Workers *connect)
{
    
    
     for (int i = 0; i < 20 ; i++)
                {
                    //this condition will check if there is a patient has been registered twice
                    if (nurses [i]==connect)
                    {
                      cout << "The Nurse is aleady working in the room."<<endl;;
                        break;
                        
                    }
                    //this will add a new patient
                    else if (nurses [i]==nullptr)
                        {
                          nurses [i]=connect;
                            break;
                        }
                    
                        
                        
                    }
                    //will check if exceed the number of patients allowed to each student
                    bool exceed=false;
                    
                    for (int i = 0 ; i <20 ; i++)
                      {  if ((nurses [i]==connect)&&(nurses [i]!=nullptr))
                            exceed=true;
                            
                      }
              

           if (exceed==false)
              { cout<<"you exceed the limit of the Nurses in The room"<<endl;}
        
        matchNuwithRoom() ;
    }


void Hospital::matchIfectedwithRooms(Infected * connect)
{
    if (connect->getCurrentRoom()== "EmergancyRoom")
        emergancyrooms.MatchClasses(connect);
    else if (connect->getCurrentRoom()== "QuaratineRoom")
        quaratinerooms.MatchClasses(connect);
    else 
    {cout << "There is no matching room with the same name..."<<endl;}
    
}


void Hospital::matchDrwithRooms() 
{
   indexconter();

    for (int i = 0 ; i <indexDr ; i++)
    {
        if (doctors[i]->getWorkingRoom() == "EmergancyRoom")
            emergancyrooms.MatchClasses(doctors[i]);
        else if (doctors[i]->getWorkingRoom() == "QuaratineRoom")
             quaratinerooms.MatchClasses(doctors[i]);
    }
    
    
}
void Hospital::matchNuwithRoom() 
{
    indexconter();

    for (int i = 0 ; i <indexNu ; i++)
    {
        if (nurses[i]->getWorkingRoom() == "EmergancyRoom")
            emergancyrooms.MatchClasses(nurses[i]);
        else if (nurses[i]->getWorkingRoom() == "QuaratineRoom")
             quaratinerooms.MatchClasses(nurses[i]);
    }
     
    
}






  void Hospital::indexconter()
  {
      
      int tempnum=0;
              for (int i = 0 ; i <20 ; i++)
              {
                  if (nurses [i]==nullptr)
                      tempnum++;
              }
                 
                indexNu=20-tempnum;
                
        int tempnum1=0;
              for (int i = 0 ; i <20 ; i++)
              {
                  if (doctors [i]==nullptr)
                      tempnum1++;
              }
                 indexDr=20-tempnum1; 
                 
      
      }
