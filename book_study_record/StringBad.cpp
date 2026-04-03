#include "StringBad.h"
#include <cstring>
using std::cout;

// initialize static class member
int StringBad::num_strings = 0;

// class methods
// construct StringBad from C string
StringBad::StringBad(const char *s)
{
	len = 0;
	while (s[len] != '\0')
		len++; // set size
	str = new char[len + 1]; // allot storage
	for(int i = 0; i < len; i++)
		str[i] = s[i]; // copy string to new storage
	str[len] = '\0'; // terminate string
	num_strings++; // set object count
	cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad()
{
	len = 4;
	str = new char[4];
	str[0] = 'C';
	str[1] = '+';
	str[2] = '+';
	str[3] = '\0';
	num_strings++;
	cout << num_strings << ": \"" << str << "\" default object created\n";
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\" object deleted, ";
	--num_strings; // required
	cout << num_strings << " left\n";
	delete [] str;
}

std::ostream &operator<<(std::ostream &os, const StringBad &st)
{
	os << st.str;
	return os;
}