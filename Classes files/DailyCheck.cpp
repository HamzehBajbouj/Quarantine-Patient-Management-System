#include "DailyCheck.h"
#include <iostream>
#include <string>
using namespace std;


DailyCheck::DailyCheck(string medicine ,string breakfast,string lunch, string dinner , string drinks )
{
    Medicine=medicine;
    BreakFast=breakfast;
    Lunch=lunch;
    Dinner=dinner;
    Drinks=drinks;
    
    Newsymptoms[0] = "No Newsymptom";
    Newsymptoms[1] = "No Newsymptom";
}



DailyCheck::~DailyCheck()
{
}

string   DailyCheck::getNewsymptoms(int i)
        {return Newsymptoms[i];}

 string DailyCheck::getMedicine() const
            {return Medicine;}
            
 string DailyCheck::getBreakFast() const
            {return BreakFast;}
            
 string DailyCheck::getLunch() const
            {return Lunch;}
            
 string DailyCheck::getDinner() const
            {return Dinner;}
            
 string DailyCheck::getDrinks() const
            {return Drinks;}
            


 void DailyCheck::setFood(string breakfast,string lunch,string dinner,string drinks)
        {
            BreakFast=breakfast;
            Lunch=lunch;
            Dinner=dinner;
            Drinks=drinks;
        }
    
 
    void DailyCheck::setNewsymptoms()
      {
          cout <<"**** You are Allowed to Enter Only two Symptoms for each Day ****"<<endl;
          cout << "Enter the First Symptom :: ";
            cin >> Newsymptoms[0];
            
            char check;
            cout << "To Enter the Second Symptom Enter |Y| ::";
            cin >>check;
              if ((check == 'y') || (check == 'Y'))
              {
                  cout << "Enter the Second Symptom :: ";
                  cin >> Newsymptoms[1];
            }
            else
                cout <<"You Chose to not enter any other Symptom.\nThe Second Symptom will be Set to NoSymptom"<<endl;
        }
        
        
    void  DailyCheck::setNewsymptomsByPassing (int index, string value)
           {
               Newsymptoms[index]= value;
            }
 
        
    
    void DailyCheck::setMedicine(string medicine)
        {Medicine=medicine;}
        


    ostream &operator<<(ostream &output ,const DailyCheck  &objcet )
    {
        output<<"The Newsymptoms :: "<<objcet.Newsymptoms[0]<<"....."<<objcet.Newsymptoms[1]<<endl;
        output<<"Medicine :: "<<objcet.Medicine<<endl;
        output<<"BreakFast :: "<<objcet.BreakFast<<endl;
        output<<"Lunch :: "<<objcet.Lunch<<endl;
        output<<"Dinner :: "<<objcet.Dinner<<endl;
        output<<"Drinks :: "<<objcet.Drinks<<endl;
         
       return  output;}
          
          
          
     istream &operator>>(istream &input ,DailyCheck  & object)
     {
         char check;
         
         cout<<"Is there Newsymptoms ?? N/Y :: ";
         input>>check;
         input.ignore();
         if ((check == 'y') || (check == 'Y'))
         {
             cout << "Enter the Newsymptom :: ";
                getline(input, object.Newsymptoms[0]);
             cout<<"Is there any other Newsymptoms ?? N/Y :: ";
                input >>check;
                input.ignore();
                    if ((check == 'y') || (check == 'Y'))
                    {       cout << "Enter the Newsymptom :: ";
                                getline(input, object.Newsymptoms[1]);
                    }
         }
         
         cout << "Insert The Medicine Taken for Today :: ";
          //  input >>object.Medicine;
            getline(input,object.Medicine);
         cout << "Enter The Breakfast Meal for Today :: ";
            //input >>object.BreakFast;
             getline(input,object.BreakFast);
        cout << "Enter The Lunch Meal for Today :: ";
            //input >>object.Lunch; 
             getline(input,object.Lunch);
         cout << "Enter The Dinner Meal for Today :: ";
            //input >>object.Dinner;
              getline(input,object.Dinner);
         cout << "Enter The Drink for Today :: ";
            //input >>object.Drinks;
            getline(input,object.Drinks);
         return input;}
         
        
        string & DailyCheck::operator[](int i)
        {
            if (i > 2 )
                {
                    cout <<"You Have inserted a wrong number for the index"<<endl;
                    string Error= "ERROR IN THE INDEX";
                    return Error;
                }
            else
            return Newsymptoms[i];
        }
        
  