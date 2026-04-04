#pragma once
#include <iostream>
#ifndef STRINGBAD_h
#define STRINGBAD_h

class StringBad
{
private:
	char *str; // pointer to string
	int len; // length of string
	static int num_strings; // number of objects

public:
	StringBad(const char *s); // constructor
	StringBad(); // default constructor
	StringBad(const StringBad& st); // deep copy
	~StringBad(); // destructor

	StringBad& operator=(const StringBad& st);
	
	// friend function
	friend std::ostream &operator<<(std::ostream &os, const StringBad &st);

};

#endif // !STRINGBAD_h



