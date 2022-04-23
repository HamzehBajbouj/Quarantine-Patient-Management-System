#ifndef INFECTED_H
#define INFECTED_H
#include "Patient.h"
#include <iostream>
#include <string>
#include "PatientInformation.h"
#include "DailyCheck.h"
using namespace std;

class Infected : public Patient
{
protected:

  //  string PeopleInContact[5];
    string PatientConditon;
    DailyCheck dailycheck[3];
public:
    Infected();
    ~Infected();
    
  //this is the inhrited vritural method
    void setAllPatientInfo ();
    
    
    //these methods to get the daily check information needed when we write in the files
    
    string Da_getNewsymptoms(int i,int k)
        {return dailycheck[i].getNewsymptoms(k);}
        
    string Da_getMedicine(int i) 
    {
        return dailycheck[i].getMedicine();
    }
    
    string Da_getBreakFast(int i )
    {
        return  dailycheck[i].getBreakFast();
    }
    
    string Da_getLunch(int i )
    {
        return  dailycheck[i].getLunch();
    }
    
    string Da_getDinner(int i )
    {
        return  dailycheck[i].getDinner();
    }
    
       string Da_getDrinks(int i )
    {
        return  dailycheck[i].getDrinks();
    }
    
    string getdaildddycheck(int i)
    {
        
        return dailycheck[i].getNewsymptoms(0)+","+dailycheck[i].getNewsymptoms(1)+","+dailycheck[i].getMedicine()+","+ dailycheck[i].getBreakFast()+","+dailycheck[i].getLunch()+","+dailycheck[i].getDinner()+","+dailycheck[i].getDrinks();
    }
    //these two functions are related to the PeopleInContact array
    //string getPeopleInContact (int );
   //void setPeopleInContact(int , string);
    
    //these two functions are related to the PatientConditon
    string getPatientConditon () const;
    void setPatientConditon (string);
    
   //related to the dalycheck array
   //for this method there will be a list to determine what the information need to show
   void getdailycheck (int =3,bool=false) ;
   
   //this method will be helpfull when reading from txt
   void setDataFordailycheck(int,string,string,string,string,string,string,string);
   //there will be a lists here one to set all the information by cin>> and other opitons one by one
   void setDataFordailycheck(int ) ;
   
   void showAllSymptoms();
   
   void  DisplayaSpcificInfo() ;
   
    friend ostream &operator<<(ostream & ,const Infected  & );
   
};

#endif // INFECTED_H


