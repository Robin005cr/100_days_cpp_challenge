/*
* project   : https://github.com/Robin005cr/100_days_cpp_challenge
* file name : Day1.cpp
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
#include <vector>
using namespace std;

int main() {
    int number = 4356;
    vector<int> digits;

    // Extract digits from end (least significant to most)
    while (number > 0) {
        digits.push_back(number % 10); // get last digit
        number /= 10;                  // remove last digit
    }

    
    reverse(digits.begin(), digits.end());

    
    for(int d : digits)
        cout << d << " ";
    return 0;
}
