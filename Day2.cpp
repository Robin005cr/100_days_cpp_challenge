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