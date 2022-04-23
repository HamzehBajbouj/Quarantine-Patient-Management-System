#include "Infected.h"
#include "Patient.h"
#include <iostream>
#include <string>
#include "PatientInformation.h"
using namespace std;

Infected::Infected()
{
        /*for (int i= 0 ; i < 5 ; i ++)
        PeopleInContact[i]="Null";*/
    PatientConditon="Null";
}

Infected::~Infected()
{
}

    
  //this is the inhrited vritural method
    void Infected::setAllPatientInfo ()
        {cin >>patientInfo;}
    
  /*  
    //these two functions are related to the PeopleInContact array
    string Infected::getPeopleInContact (int i)
            {return PeopleInContact[i];}
            
    void  Infected::setPeopleInContact(int i, string name)
        { PeopleInContact[i]= name;}
    
    */
    
    //these two functions are related to the PatientConditon
    string Infected::getPatientConditon () const
        {return PatientConditon;}
        
    void  Infected::setPatientConditon (string conditon)
        {PatientConditon=conditon;}
    
    
    
    
    
   //related to the dalycheck array
   //for this method there will be a list to determine what the information need to show
   
   void Infected::getdailycheck (int i,bool checking)
   {
       
       if (checking==true)
       {
           for (int k = 0 ; k < i; k++)
               {cout <<dailycheck[k]<<endl;}
               for (int f=0 ; f <50; f++)
                   cout<<"-";
                cout <<endl;
           
        }
        else
        {
            int num = 32;
            cout <<"Choose the Infomation needed by Entering its Number\n\n";
            cout<<"1- Display all the Inforamtion"<<endl;
            cout<<"2- Display the Medicine"<<endl;
            cout<<"3- Display the Meals eaten"<<endl;
            cout<<"4- Show the Symptoms"<<endl;
            cout <<"5- Exit"<<endl;
        
        for (;num !=5 ;)
        {
             cout<<"Enter a Number :: ";
            cin >> num;
            cin.ignore();
            if (num==1)
                    {cout <<dailycheck[i]<<endl;}
            else if (num==2)
                {cout <<dailycheck[i].getMedicine()<<endl;}
            else if (num ==3 )
                {
                    cout<<"The Breakfast Meal :: " <<dailycheck[i].getBreakFast()<<"   The Lunch Meal :: "<<dailycheck[i].getLunch()<<endl;
                    cout<<"The Dinner Meal :: " <<dailycheck[i].getDinner()<<"   The Drink :: "<<dailycheck[i].getDrinks()<<endl;
                    }
            else if (num == 4)
                {
                    cout << "The New Symptoms for This Day are "<<endl;
                        cout <<"1- "<<dailycheck[i].getNewsymptoms (0)<<endl;
                        cout <<"2- "<<dailycheck[i].getNewsymptoms (1)<<endl;
                }
                
            else 
                {break;}
            
            }
        
        }
       
       }
   
   
   
   
   void Infected::setDataFordailycheck(int i,string medicine,string breakfast,string lunch,string dinner,string drink,string sym1 , string sym2)
   {
       dailycheck[i].setFood(breakfast,lunch,dinner,drink);
       dailycheck[i].setMedicine(medicine);
       dailycheck[i].setNewsymptomsByPassing (0 , sym1);
       dailycheck[i].setNewsymptomsByPassing (1 , sym2);
    }
   
   
   //there will be a lists here one to set all the information by cin>> and other opitons one by one
   void Infected::setDataFordailycheck(int i)
   
   {
       cout <<"Choose the Number of Method"<<endl;
       cout <<"0- To set OR Reset all the inforamtion for this Day."<<endl;
       cout<<"1- To Edit The Meals"<<endl;
       cout<<"2- To Edit The Medicine Taken"<<endl;
       cout<<"3- To Edit The Symptoms "<<endl;
       cout<<"4- Exist "<<endl;
       
         int num = 32;
         string meal1="Null",meal2 ="Null",meal3="Null",meal4="Null";
         string store1,store2;
         for (;num !=4 ;)
        {
             cout<<"Enter Method Number :: ";
            cin >> num;
            cin.ignore();
            if (num==0)
                    {cin>>dailycheck[i];}
                    
            else if (num==1)
                {cout <<"Enter The new Data *note Insert NULL\n if there is nothing you want to change"<<endl;
                    cout <<"Enter BreakFast ::";
                        getline(cin,meal1);
                     cout <<"Enter Lunch ::";
                        getline(cin,meal2);
                     cout <<"Enter Dinner ::";
                        getline(cin,meal3);
                     cout <<"Enter Drink ::";
                        getline(cin,meal4);
                    dailycheck[i].setFood(meal1,meal2,meal3,meal3);
                
                }
                
                
                
            else if (num ==2 )
                {
                    cout <<"Enter The Medicine :: ";
                    getline(cin,store1);
                    dailycheck[i].setMedicine(store1);
                }
            else if (num == 3)
                {
                    cout << "Enter The New Symptoms "<<endl;
                        cout <<"1- :: ";
                        getline(cin,store1);
                        cout <<"2- :: ";
                        getline(cin,store2);
                        dailycheck[i].setNewsymptomsByPassing (0 , store1);
                        dailycheck[i].setNewsymptomsByPassing (1 , store2);
                }
                
            else 
                {break;}
            
            }
       
       }
   
   
   
   void Infected::showAllSymptoms()
   {
       cout <<"ALL the Symptoms that have appeared on the Patient"<<endl;
       for (int i = 0 ; i < 7 ; i++)
           cout <<"["<<symptoms[i]<<"]"<<endl;
        
       /* for (int i = 0 ; i<3 ; i++)
        {
            for (int k=0 ; k <7 ; k++)
                {if ( symptoms[k]!=dailycheck[i].getNewsymptoms(0))
                    cout <<"["<<dailycheck[i].getNewsymptoms(0)<<"]"<<endl;
                if ( symptoms[k]!=dailycheck[i].getNewsymptoms(1))
                     cout <<"["<<dailycheck[i].getNewsymptoms(1)<<"]"<<endl;
                }
            }
       
       */
       }
   
   
   
     ostream &operator<<(ostream &output ,const Infected  &object )
     {
         output<<":::SUMMARY OF PATIENT INFORAMTION :::"<<endl;
         output << object.patientInfo;
         output <<"Patient ID :: "<<object.PatientID<<endl;
         output <<"Patient current hospital room :: "<<object.CurrentRoom<<endl;
         output <<"Patient level of condition :: "<<object.PatientConditon<<endl;
   
         
    return output;}
   
void  Infected:: DisplayaSpcificInfo() 
{
  
 
     cout<<"To Display a Spcific information Choose the Number you want\n\n";
            int chosenNum=434;
            string insertedInformation;
            cout<<"0- Display the All Patient's Information"<<endl;
            cout <<"1- Patient Name"<<endl;
            cout <<"2- Patient PhoneNumber"<<endl;
            cout <<"3- Patient Address"<<endl;
            cout <<"4- Patient ID"<<endl;
            cout <<"5- Patient Condition"<<endl;
            cout <<"6- Patient Current Room"<<endl;
            cout <<"7- Exit"<<endl;
            
            for (; chosenNum!=7 ; )
            {
                cout<<"Enter a Number :: ";
                cin>>chosenNum;
                cin.ignore();
                if (chosenNum==0)
                    {cout<<patientInfo;
                     cout <<"ID :: "<<PatientID<<"    Condition :: "<<PatientConditon<<endl;
                     cout <<"Current Room :: " << CurrentRoom<<endl;
                    }
                
                else if (chosenNum==1)
                {
                  cout<<"Name :: "<<patientInfo.getpatientName()<<endl;
                }
                
                else if (chosenNum==2)
                {
                   cout<<"Phone Number :: "<<patientInfo.getpatientPhoneNumber()<<endl;
                }
                
                else if (chosenNum==3)
                 {
                  cout<<"Address :: "<<patientInfo.getpatientAddress()<<endl;
                }
                
                else if (chosenNum==4)
                    {cout <<"ID :: "<<PatientID<<endl;}
                else if (chosenNum==5)
                    {cout <<"Condition :: "<<PatientConditon<<endl;}
                else if (chosenNum==6)
                    {cout <<"Current Room :: "<<CurrentRoom<<endl;}
                else
                {break;}
              
            }
    }