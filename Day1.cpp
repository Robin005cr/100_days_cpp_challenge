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
