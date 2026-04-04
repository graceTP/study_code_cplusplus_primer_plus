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
	cout << num_strings << ": \"" << str << "\" object created by char*\n";
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

StringBad::StringBad(const StringBad& st)
{
	num_strings++;

	len = st.len;
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
		str[i] = st.str[i]; // copy string to new storage
	str[len] = '\0'; // terminate string

	cout << num_strings << ": \"" << str << "\" object created by copy construct\n";
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\" object deleted, ";
	--num_strings; // required
	cout << num_strings << " left\n";
	delete [] str;
}

StringBad& StringBad::operator=(const StringBad& st)
{
	if (this == &st)
		return *this;

	delete[] str;

	len = st.len;
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
		str[i] = st.str[i]; // copy string to new storage
	str[len] = '\0'; // terminate string

	return *this;
}

std::ostream &operator<<(std::ostream &os, const StringBad &st)
{
	os << st.str;
	return os;
}