#ifndef DEFENTION_H
#define DEFENTION_H
#include "string.h"
class Definition {
private:
	String Word;
	int NumOfTranslate;
	String* Define;
	friend class Dictionary;
public:
	Definition();
	~Definition();
	Definition(const Definition&);
	Definition& operator=(const Definition& x);
	bool operator==(const Definition& x)const;
	bool operator!=(const Definition& x);
	void operator<<(const Definition& x)const;
	Definition& operator >> (const Definition& x);
	Definition& operator-=(const int x);
	Definition&  operator+=(const String& x);
	Definition& FindWord(const char x[]);
	void PrintWord()const;
	Definition& AddDefinition(Definition& tmp);
	bool operator[](const char x[]);
	char* GetWord();
	//Definition& buildDefintion(int x);
	//Definition getDef(Definition x);
	//void setNumOfTranslate(int x);
	//String& makeDefintion(int &num, char** str);
	//bool FixDefintion(char *str, int num)const;
	//Definition& CopyDEF(const Definition& x);
};
#endif // !DEFENTION_H
#pragma once
