/*
* project   : https://github.com/Robin005cr/100_days_cpp_challenge
* file name : Day2.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
#include <iostream>
using namespace std;

struct InnovaPetrol
{
    string firstName;
    string secondName;
    string modelYear;
    
};

struct InnovaDiesel
{
    string firstName;
    string secondName;
    string modelYear;
    string tyrePressure;
    void getEngineDetails()
    {
        cout<<"This is diesel engine"<<endl;
    }
    //conversion constructor
InnovaDiesel(const InnovaPetrol& p)
        : firstName(p.firstName), secondName(p.secondName), modelYear(p.modelYear) {}
    
};
int main()
{
     InnovaPetrol p{"Toyota","Innova","2025"};
     
     InnovaDiesel d = p;
     cout<<d.firstName<<" "<<d.secondName<<" "<<d.modelYear<<endl;
    

    return 0;
}