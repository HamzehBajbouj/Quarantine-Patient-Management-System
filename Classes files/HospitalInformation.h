#ifndef HOSPITALINFORMATION_H
#define HOSPITALINFORMATION_H
#include <iostream>
#include <string >
using namespace std;


class HospitalInformation
{
private :

    string HospitalName;
    string HopitalLocation;
    string HopitalContactNum;
public:
    HospitalInformation(string name="Null", string num="Null", string location = "Null");
    ~HospitalInformation();
    
  string  getHospitalName ()
    {return HospitalName;}

  string  getHopitalLocation ()
    {return HopitalLocation;}
  
   string getHopitalContactNum ()
    {return HopitalContactNum;}
   
    void setHopitalContactNum (string contactnum)
        {HopitalContactNum =contactnum;}
    void setHospitalName (string name) 
        {HospitalName=name;}
    
     void setHopitalLocation (string location)
     {HopitalLocation = location;}
};

#endif // HOSPITALINFORMATION_H
