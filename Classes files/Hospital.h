#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <iostream>
#include <string>
#include "Doctor.h"
#include "Workers.h"
#include "QuaratineRoom.h"
#include "EmergancyRoom.h"
#include "HospitalInformation.h"
using namespace std;

class Hospital
{
    
private :
HospitalInformation HopitalInfo ;
EmergancyRoom emergancyrooms ; 
QuaratineRoom quaratinerooms ;
Workers * nurses[20];
Doctor *doctors [20] ;
  void indexconter();
int indexDr ; 
int indexNu ;

public:
    Hospital();
    ~Hospital();
    
    
    
    
    /*
     * these methods are related to the hospital information object
     * will be used when we read from the files
     */
    
       void sethopitallocation (string );
       void sethospitalname (string ) ;  
       void sethopitalcontactnum (string) ;
       void displayHosptalInformation () ;
       
    /*
     * these methods are to write on the files
     * */
    string gethopitallocation()
        {return HopitalInfo.getHopitalLocation();}
    string gethospitalname()
        {return HopitalInfo.getHospitalName();}
        
    string gethopitalcontactnum()
    {
        return HopitalInfo.getHopitalContactNum();
    }
    /*
     * these methods are for the hospital rooms 
     * the point is to pass the information from the main program into these objcet
     * 
     * */
    void EMsetBedsNumber(int x)
        {emergancyrooms.setBedsNumber(x);}
    
    void EMsetAvailabeBeds(int x) 
        {emergancyrooms.setAvailabeBeds(x);}
    
    void EMsetCapacityStatus(bool x) 
        {emergancyrooms.setCapacityStatus(x);}
    
    int EMgetBedsNumber( )
        {return emergancyrooms.getBedsNumber();}
    int EMgetAvailabeBeds() 
        {return emergancyrooms.getAvailabeBeds();}
    void EMDisplaySummary()
        {emergancyrooms.DisplaySummary();}
    void EMsetTotalMechanicalVentilation (int x)
        {emergancyrooms.setTotalMechanicalVentilation(x);}
        
   // void EMsetMechanicalVentilationUnderUse (int x)
   //   void EMCalculateMechanicalVentilationAvailabe ()  
    //void EMCalculateBedsAvailable ()    private
    int EMgetTotalMechanicalVentilation()
        {return emergancyrooms.getTotalMechanicalVentilation();}
    
    int EMgetMechanicalVentilationUnderUse () 
        {return emergancyrooms.getMechanicalVentilationUnderUse();}
      
    bool EMgetCapacityStatus( ) 
        {return emergancyrooms.getCapacityStatus();}


   void QRsetBedsNumber(int x) 
    {quaratinerooms.setBedsNumber(x);}
   void QRsetAvailabeBeds(int x)
    {quaratinerooms.setAvailabeBeds(x);}
   void QRsetCapacityStatus(bool x)
    {quaratinerooms.setCapacityStatus(x);}
    
   int QRgetBedsNumber( )
    {return quaratinerooms.getBedsNumber();}
    
   int QRgetAvailabeBeds()
   {return quaratinerooms.getAvailabeBeds();}
   
   void QRSetRoomResidentsbyPassing(int x, string st1,string st2,string st3)
    {quaratinerooms.SetRoomResidentsbyPassing(x,st1,st2,st3);}
    
   void QRDisplaySummary() 
    {quaratinerooms.DisplaySummary();}
    
   void QREditQuDetailsForPatient (string idp)
    {quaratinerooms.EditQuDetailsForPatient(idp);}
    
   int QRgetTotalnumerOfDaysSpent ()
   {return quaratinerooms.getTotalnumerOfDaysSpent();}
   
   int QRgetNumberOfDaysSpentForspecificID (string id)
    {return quaratinerooms.getNumberOfDaysSpentForspecificID(id);}
    
   string QRgetStartingDateByID(string id)
    {return quaratinerooms.getStartingDateByID(id);}
    
   string QRgetExitingDateByID  (string id)  
   {return quaratinerooms.getExitingDateByID(id);}
   
   void QRsetStartingDateByID (string ID ,string nDate)
   {quaratinerooms.setStartingDateByID(ID,nDate);}
   
   void QRsetExitingDateByID  (string id ,string Ndate ) 
    {quaratinerooms.setExitingDateByID(id,Ndate);}
    
   void QRCalculateBedsAvailable () 
        {quaratinerooms.CalculateBedsAvailable();}
   bool QRgetCapacityStatus( )
    {return quaratinerooms.getCapacityStatus();}


    void QRsetIDforRoomRsidents(string previousID, string NewID)
    {
        quaratinerooms.setIDforRoomRsidents(previousID,NewID);
        
    }


string   QRgetRoomResidents(int i)
{
    
  return  quaratinerooms.getRoomResidents(i);
    
}
void matchDr(Doctor* ) ;
void matchNurses(Workers *) ;
void matchIfectedwithRooms(Infected * ) ;
void matchDrwithRooms() ;
void matchNuwithRoom()  ;

    
void QRsetid(string idx)
{
    quaratinerooms.setid(idx); 
}
};

#endif // HOSPITAL_H
