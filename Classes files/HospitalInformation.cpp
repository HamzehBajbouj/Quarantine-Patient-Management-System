#include "HospitalInformation.h"
#include <iostream>
#include <string >
using namespace std;

HospitalInformation::HospitalInformation(string name, string num, string location)
{
     HospitalName =name;
     HopitalLocation=location;
     HopitalContactNum =num;
}

HospitalInformation::~HospitalInformation()
{
}

