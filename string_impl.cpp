/*
* project   : https://github.com/Robin005cr/100_days_cpp_challenge
* file name : string_impl.cpp
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
#include<iostream>
#include<cstring>
using namespace std;
class stringContainer
{
private:
	char *data;
	size_t size;
	size_t capacity;
public:
	void memalloc(size_t new_capacity) {
		data = new char[new_capacity];
		capacity = new_capacity;
	}
	void dealloc() {
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
	}
	// Default constructor
	stringContainer() : data(nullptr), size(0), capacity(0) {}

	// Parametrised Ctor
	stringContainer(const char* str) {
		size = strlen(str);
		capacity = size + 1;
		memalloc(capacity);
		strcpy(data, str);
	}
	stringContainer(const stringContainer& other);
	stringContainer& operator=(const stringContainer& other);
	~stringContainer()
	{
		dealloc();
	}
};


stringContainer::stringContainer(const stringContainer& other):data{nullptr},size{other.size},capacity{other.capacity}
{
	memalloc(capacity);
	strcpy(data,other.data);
}
stringContainer& stringContainer::operator=(const stringContainer& other)
{
	if(this!=&other)
	{
		dealloc();
		size = other.size;
		capacity = other.capacity;
		memalloc(capacity);
		strcpy(data,other.data);

	}
	return *this;
}
int main()
{

	stringContainer S1 = "Hello";  // Parametrised Ctor
	stringContainer S2 = S1;       // Copy Ctor

	stringContainer S3;            // Default Ctor
	S3 = S2;                        // Copy assignment operator
	return 0;

}