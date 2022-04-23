#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H
#include <iostream>
#include <string>
#include "Patient.h"
#include "Infected.h"
#include "Workers.h"
#include "Doctor.h"
#include "QuaratineRoom.h"
#include "EmergancyRoom.h"

using namespace std;

class LogInSystem
{
private:
    string adminID;
    string PateintsIDs [140];
    string DoctoresIDs [20];
    string NuresesIDs[20];
    Workers * Nureses [20];
    Doctor  * doctors [20];
    Infected * Patients [140];
    void IndexCounter();
    int IndexCountNu;
    int IndexCountDo;
    int IndexCountPa;
    void connectID (string );
public:
    LogInSystem();
    ~LogInSystem();
    void MatchClasses(Workers *) ;
    void MatchClasses(Doctor *) ;
    void MatchClasses(Infected *) ;
    bool checkID (string );
    
    int getIndexCountNu()
        {
            IndexCounter();
            return IndexCountNu;
        }
    
    
    int getIndexCountDo()
    {
        IndexCounter();
        return IndexCountDo;
    }
    
    
    int getIndexCountPa()
     {
        IndexCounter();
        return IndexCountPa;
    }
    
    
   void updateID_PA(string previousid ,string newid)
   {
       IndexCounter();
       
       for (int i =0 ; i <IndexCountPa ; i++)
           
           {
               if (PateintsIDs[i]==previousid)
               {
                   PateintsIDs[i]=newid;
                   break;
                }
               
            }
    }
    
     void updateID_DO(string previousid ,string newid)
   {
       IndexCounter();
       
       for (int i =0 ; i <IndexCountDo ; i++)
           
           {
               if (DoctoresIDs[i]==previousid)
               {
                   DoctoresIDs[i]=newid;
                   break;
                }
               
            }
    }
    
         void updateID_NU(string previousid ,string newid)
   {
       IndexCounter();
       
       for (int i =0 ; i <IndexCountNu ; i++)
           
           {
               if (NuresesIDs[i]==previousid)
               {
                   NuresesIDs[i]=newid;
                   break;
                }
               
            }
    }
    
};

#endif // LOGINSYSTEM_H

