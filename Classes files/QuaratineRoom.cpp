#include "QuaratineRoom.h"
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Workers.h"
#include "Infected.h"
#include "HospitalRooms.h"
#include <cstdlib>
#include  <stdlib.h> 
using namespace std;


QuaratineRoom::QuaratineRoom()
{
    for (int i = 0 ; i < 70 ; i ++)
    {
     //   RoomResidents [i].numerOfDaysSpent = 0;
        RoomResidents[i].StartingDate ="00|00|0000"; //DD,MM,YYYY
        RoomResidents[i].ExitingDate ="00|00|0000";
       RoomResidents[i].PatientID ="Null";
    }
    /*IndexCounter ();
    for (int i= 0 ; i <IndexCountPa; i++)
         {RoomResidents[i].PatientID = infected_patients[i]->getPatientID();}*/
       
}

QuaratineRoom::~QuaratineRoom()
{
}

//this method is for reading from the files
void QuaratineRoom::SetRoomResidentsbyPassing(int index, string StartDate,string exitDate,string idp)
{
    
    RoomResidents[index].StartingDate=StartDate;
    RoomResidents[index].ExitingDate=exitDate;
    RoomResidents[index].PatientID=idp;
}

//note: this method will also count the starting date,
int QuaratineRoom::calcualteDayspent(string startD,string exitD)
{
    int daysspent;
    int start =  (stoi(startD.substr(0,2))+ (stoi(startD.substr(3,2))-1 ) *31);
    int end =(stoi(exitD.substr(0,2))+((stoi(exitD.substr(3,2))-1 )*31));
    daysspent=end-start+1;
   
    return daysspent;  
}


 void QuaratineRoom::CalculateBedsAvailable ()
 {
     IndexCounter ();
     
     AvailabeBeds = BedsNumber-IndexCountPa;
     if (AvailabeBeds==0)
         CapacityStatus=false;
}


//displaySummary will show the total day for all the patient
 void QuaratineRoom::DisplaySummary()
 {
     int totalday=0;
     IndexCounter ();
     internalser();
     for (int i = 0 ; i < IndexCountPa ; i ++)
         totalday+=calcualteDayspent(RoomResidents[i].StartingDate, RoomResidents[i].ExitingDate);
    
      int highDa=0,modDa=0,LowDa=0;
        for (int i = 0 ; i < IndexCountPa ; i++)
        {
            if (infected_patients[i]->getPatientConditon() =="High")
                highDa+=1;
            else if (infected_patients[i]->getPatientConditon() =="Moderate")
                modDa+=1;
            else if (infected_patients[i]->getPatientConditon() =="Low")
                LowDa+=1;
        }
        int firstpatient = 10000;
        string firstpatientdate;
        string idPat;
       //this method is to find the date for the first patient was in the room
        for (int i = 0 ; i < IndexCountPa   ; i ++)
        {
            
            if (firstpatient > (stoi(RoomResidents[i].StartingDate.substr(0,2))+ (stoi(RoomResidents[i].StartingDate.substr(3,2)) ) *31))
               { firstpatient=(stoi(RoomResidents[i].StartingDate.substr(0,2))+ (stoi(RoomResidents[i].StartingDate.substr(3,2)) ) *31);
                    firstpatientdate=RoomResidents[i].StartingDate;
                    idPat = RoomResidents[i].PatientID;
              
               }
        }
            
        CalculateBedsAvailable ();
        
        
        string Capacity;
        
        if (CapacityStatus==false)
        {
            Capacity="Full"; 
        }
        else 
            {Capacity = "Not Full";}
            
            
        cout <<":::Quaratine Room Patient Summary:::"<<endl;
        cout <<"There are ["<<AvailabeBeds<<"] available Beds in the Room "<<endl;
        cout <<"The Beds Capacity Status is ["<<Capacity<<"]"<<endl;
        cout <<"You Have "<<IndexCountPa << " Patients in the Quaratine Room "<<endl;
            cout <<":: Their conditions are ::"<<endl;
            cout <<"["<<highDa<<"] is High Condition"<<endl;
            cout <<"["<<modDa<<"] is Moderate Condition"<<endl;
            cout <<"["<<LowDa<<"] is Low Condition"<<endl;
        cout <<"The total Day spent for All Patients ["<<totalday<<"] Days."<<endl;
        cout <<"The First Case Entered the Room was on ["<<firstpatientdate<<"] for ID number ["<<idPat<<"]"<<endl;
        cout <<"There are ["<<IndexCountDo<<"] Doctors Working in this Room."<<endl;
        cout <<"There are ["<<IndexCountNu<<"] Nurses Working in this Room."<<endl;
        

}
 
 

 void QuaratineRoom::EditQuDetailsForPatient (string idpatient_1)
 {
      IndexCounter ();
      internalser();
     // string idpa;
      bool check;
      int indexnum;
      
      //Note there is no any use for these lines but we kept them in case we want to change the way how the system works
      /*
      cout <<"To Edit the Quaratine information for specific patient"<<endl;
      cout <<"Please insert the patient's ID :: ";
       
      label1:
      getline(cin,idpa);*/
      
     for (int i = 0 ; i <IndexCountPa ; i ++  )
        {
            if (idpatient_1== RoomResidents[i].PatientID)
                {check=true;
                indexnum=i;
                break;}
            else
                check=false;
        }
        
        char trying;
        if (check == false)
            {cout <<"Either There is no patient for this ID in the Qurartine Room Or the Patient is in a different Room......"<<endl;
             //Note there is no any use for these lines but we kept them in case we want to change the way how the system works
         /*   cout <<"to try again please enter [y] ::";
            cin >>trying;
            if ((trying=='y')||(trying=='Y'))
                    goto label1;
            else 
                cout <<"You chose to Exit from this list"<<endl;*/
            }
            
        if (check==true)
        {
            
            
            int chosenNum=43434;
            string insertedInformation;
            cout<<"0- Display the Quaratine information"<<endl;
            cout <<"1- Starting Date"<<endl;
            cout <<"2- Exiting Date"<<endl;
            cout <<"3- Display Number of Days spent"<<endl;
          //  cout <<"4- To Edit Another Patient Quaratine information"<<endl;
            cout <<"4- Exit"<<endl;
            cout<<"Note: to display Days spent the starting Date and Exiting Date should be Entered before..."<<endl;
            cout<<"Note: Number of maximum days is 3 including the starting day.."<<endl;
            for (; chosenNum!=4; )
           { cout<<"Enter a Number :: ";
                cin>>chosenNum;
                cin.ignore();
                
                 if (chosenNum==0)
                    {
                        int dayspent = calcualteDayspent(RoomResidents[indexnum].StartingDate,RoomResidents[indexnum].ExitingDate);
                        cout <<"The Current Quaratine information for ["<<idpatient_1<<"].."<<endl;
                        cout <<"Number of Days spent :: "<<dayspent<<endl;
                        cout <<"Starting Date :: "<<RoomResidents[indexnum].StartingDate<<endl;
                        cout <<"Exiting Date ::"<<RoomResidents[indexnum].ExitingDate<<endl;
                        
                        }
                
                else if (chosenNum==1)
                {
                    cout<<"Enter the New Starting Date [DD|MM|YYYY]:: ";
                   
                    getline(cin,insertedInformation);
                    RoomResidents[indexnum].StartingDate=insertedInformation;
                        
                }
                
                else if (chosenNum==2)
                {
                   lable2 : 
                    cout<<"Enter the Exiting Date :: ";
                   
                        getline(cin,insertedInformation);
                        RoomResidents[indexnum].ExitingDate=insertedInformation;
                         
                          //to check if days exceeded the limit 3 days
                     int dayspent = calcualteDayspent(RoomResidents[indexnum].StartingDate,RoomResidents[indexnum].ExitingDate);
                     if (dayspent > 3)
                        { cout<<"You have exceeded the Days allowed (3 days)."<<endl;
                            cout <<"Please Enter the Exiting Date Again :: ";
                            goto lable2;
                        }  
                         
                }
                
                
                else if (chosenNum==3)
                 {
                    int dayspent = calcualteDayspent(RoomResidents[indexnum].StartingDate,RoomResidents[indexnum].ExitingDate);
                    cout<<"The Patient Has spent ["<<dayspent<<"] Days"<<endl;
  
                }
                /* there are no usage to these statments since they are controlled by the 
                 * system premisions 
                else if (chosenNum==4 )
                {
                    system ("CLS");
                    cout <<"To Edit the Quaratine information for specific patient"<<endl;
                    cout <<"Please insert the new ID :: ";
                    goto label1;
                }*/
               
                else
                {break;}
            
            }
        
     }
 }

 
    
    int QuaratineRoom::getTotalnumerOfDaysSpent ()
    {
           int totalday=0;
     IndexCounter ();
     internalser();
     for (int i = 0 ; i < IndexCountPa ; i ++)
         totalday+=calcualteDayspent(RoomResidents[i].StartingDate, RoomResidents[i].ExitingDate);
        
        return totalday;
    }
    
    
    int QuaratineRoom::getNumberOfDaysSpentForspecificID(string idpatient)
    {
        internalser();
        int numberdays=0;
        IndexCounter ();
        for (int i = 0 ; i <IndexCountPa ; i ++)
        {
             if (idpatient==RoomResidents[i].PatientID)
             {
                numberdays= calcualteDayspent(RoomResidents[i].StartingDate, RoomResidents[i].ExitingDate);
                break;
            }
            
            }
    
        return numberdays;
    }
    
    
    
    string QuaratineRoom::getStartingDateByID  (string idpatient) 
    {
        string startdate="No Matches";
        IndexCounter ();
        internalser();
        for (int i = 0 ; i <IndexCountPa; i++ )
        {
            if (idpatient==RoomResidents[i].PatientID)
                {startdate = RoomResidents[i].StartingDate;
                 break;
                }
        }
          
        return   startdate;
    }
    
    string QuaratineRoom::getExitingDateByID   (string idpatient) 
    {
            string enddate="No Matches";
        IndexCounter ();
        internalser();
        for (int i = 0 ; i <IndexCountPa; i++ )
        {
            if (idpatient==RoomResidents[i].PatientID)
                {enddate = RoomResidents[i].ExitingDate;
                break;
                }
        }
        
    return enddate;
    }
    
    void QuaratineRoom::setStartingDateByID (string idpatient,string newdate)
    {
         IndexCounter ();
         internalser();
         int index;
         string newDateM = "No Matches";
        for (int i = 0 ; i <IndexCountPa; i++ )
        {
            if (idpatient==RoomResidents[i].PatientID)
                {   newDateM=newdate;
                   index=i;
                break;
                }
        }
         RoomResidents[index].StartingDate= newDateM;
        
    }
    
    
    void QuaratineRoom::setExitingDateByID  (string idpatient,string newdate)
    {
        IndexCounter ();
        internalser();
        string newDateM = "No Matches";
        int index;
        for (int i = 0 ; i <IndexCountPa; i++ )
        {
            if (idpatient==RoomResidents[i].PatientID)
                {newDateM= newdate;
                index=i;
                break;
                }
        }
        
        RoomResidents[index].ExitingDate=newDateM;
        
    }
    
    
    
    bool  QuaratineRoom::getCapacityStatus()
    {
    CalculateBedsAvailable ();
    
    return CapacityStatus;
    }
    
     void QuaratineRoom::setIDforRoomRsidents(string previousID, string NewID)
     {
         
        IndexCounter ();
        
        for (int i = 0 ; i < IndexCountPa ; i++)
        {
            if (RoomResidents[i].PatientID==previousID)
                {RoomResidents[i].PatientID=NewID;
                
                break;
                }
        }
        
    }
    
    int  QuaratineRoom::getPatientIDindex(int x,string id)
    {
        IndexCounter ();
        
           for (int i = 0 ; i < IndexCountPa ; i++)
        {
            if (RoomResidents[i].PatientID==id)
                return i;
        }
        
        
        
    }
    
  