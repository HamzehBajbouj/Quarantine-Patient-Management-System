#ifndef PATIENTINFORMATION_H
#define PATIENTINFORMATION_H
#include <iostream>
#include <string>
using namespace std;

class PatientInformation
{
private:
    string patientName;
    string patientPhoneNumber;
    string patientAddress;

public:
    PatientInformation(string ="Null", string ="Null", string ="Null");
    ~PatientInformation();
    
    //accessors
    string getpatientName() const;
    string getpatientPhoneNumber() const;
    string getpatientAddress() const;
    
    //mutotors
    void setpatientName(string);
    void setpatientPhoneNumber(string );
    void setpatientAddress(string);
    friend ostream &operator<<(ostream & ,const PatientInformation  & );
    friend istream &operator>>(istream & ,PatientInformation  & );
};

#endif // PATIENTINFORMATION_H
