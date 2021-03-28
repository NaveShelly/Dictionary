#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
class String {
private:
	char *Word;
	//int length;
	friend class Definition;
	friend class Dictionary;
public:
	int length;
	String();
	//~String();
	String& operator=(const String& x);
	bool operator==(const String& x)const;
	bool operator!=(const String& x)const;
	void operator<<(const String& x)const;
	String& operator >> (const String& x);
	String& operator-=(const char x);
	String& operator+=(const char x);
	char* operator[](const int x)const;
	friend bool FixWord(char*);
	int getlength()const;
	char* getstr()const;
	void setlength(int x);
};
#endif // !STRING_H
#pragma once
