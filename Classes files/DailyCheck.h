#ifndef DAILYCHECK_H
#define DAILYCHECK_H
#include <iostream>
#include <string>
using namespace std;

class DailyCheck
{
    
private:

    string Newsymptoms [2];
    string Medicine;
    string BreakFast;
    string Lunch;
    string Dinner;
    string Drinks;

public:
    DailyCheck(string ="Null",string ="Null",
    string ="Null",string ="Null",string ="Null");
    
    ~DailyCheck();
    
    
    string getNewsymptoms (int);
    
    string getMedicine () const;
    string getBreakFast() const;
    string getLunch () const;
    string getDinner () const;
    string getDrinks () const;
    
    void setFood(string ="/*NoBreakfastMeal*/",string ="/*NoLunchMeal*/",string ="/*NoDinnerMeal*/",string ="/*NoDrinks*/");
    void setNewsymptoms();
    void setMedicine(string);
    void setNewsymptomsByPassing (int , string);
    
    friend ostream &operator<<(ostream & ,const DailyCheck  & );
    friend istream &operator>>(istream & ,DailyCheck  & );
    string &operator[](int i);

};


#endif // DAILYCHECK_H
