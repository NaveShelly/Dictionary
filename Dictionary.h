#ifndef DICITONARY_H
#define DICITONARY_H
#include "Definition.h"
class Dictionary{
private:
	int NumOfDef;
	Definition* Def;
	friend class Definition;
public:
	Dictionary();
	~Dictionary();
	Dictionary(const Dictionary&);
	Dictionary& operator=(const Dictionary& x);
	bool operator==(const Dictionary& x)const;
	bool operator!=(const Dictionary& x)const;
	void operator<<(const Dictionary& x)const;
	Dictionary& operator >> (const Dictionary& x);
	Dictionary& operator -=(const int x);
	Dictionary& operator +=(const Definition& x);
	Dictionary& NewDefinition(const Dictionary& x);
	Dictionary& FindDefWord(char x[]);
	Dictionary& AddDefinition(const Dictionary& x);
	int CheckDefinition(const String x);
	void EqaulDefines();
};
#endif
