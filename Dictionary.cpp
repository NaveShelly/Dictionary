#include "Dictionary.h"
Dictionary::Dictionary()
{
	NumOfDef = 0;
	Def = NULL;
}
Dictionary::~Dictionary()
{
	for (int i = 0; i < NumOfDef; i++)
	{
		Def[i].~Definition();
	}
}
Dictionary::Dictionary(const Dictionary& x)
{
	this->operator=(x);
}
Dictionary& Dictionary :: operator=(const Dictionary& x)
{
	this->NumOfDef = x.NumOfDef;
	for (int i = 0; i < NumOfDef; i++)
	{
		Def[i].operator=(x.Def[i]);
	}
	return (*this);
}
bool Dictionary:: operator==(const Dictionary& x)const
{
	for (int i = 0; i < NumOfDef; i++)
	{
		if (this->NumOfDef != x.NumOfDef && (Def[i].operator!=(x.Def[i]))==1)
		{
			return 0;
		}
	}
	return 1;
}
bool Dictionary:: operator!=(const Dictionary& x)const
{
	if (!(this->operator==(x)))
	{
		return 1;
	}
}
void Dictionary :: operator<<(const Dictionary& x)const
{
	cout << "Your Number Of Def is :" << NumOfDef << endl;
	for (int i = 0; i < NumOfDef; i++)
	{
		cout << "Your Def in the i+1 place is: " << endl;
		Def[i].operator<<(Def[i]);
		cout << endl;
	}
}
Dictionary& Dictionary::operator >> (const Dictionary& x)
{
	cout << "Enter How Many Definition" << endl;
	cin >> NumOfDef;
	Def = new Definition[NumOfDef];
	for (int i = 0; i < NumOfDef; i++)
	{
		cout << "Enter The Name of the " << i + 1 << " Definition" << endl;
		Def[i].operator >> (Def[i]);
	}
	cout << "Your Dictionary is Ready" << endl;
	return (*this);
}
Dictionary& Dictionary::operator -= (const int x)
{
	Definition *tmp;
	tmp = new Definition[NumOfDef - 1];
	for (int i = 0; i < NumOfDef; i++)
	{
		if (i != x)
		{
			tmp[i].operator=(Def[i]);
		}
	}
	Def = new Definition[NumOfDef - 1];
	NumOfDef--;
	for (int i = 0; i < NumOfDef; i++)
	{
		Def[i].operator=(tmp[i]);
	}
	return (*this);
}
Dictionary& Dictionary::operator +=(const Definition& x)
{
	for (int i = 0; i < NumOfDef; i++)
	{
		if (Def[i].operator==(x))
		{
			cout << "This Definition is Already exits" << endl;
			return (*this);
		}
	}
	Definition *tmp;
	NumOfDef++;
	tmp = new Definition[NumOfDef];
	for (int i = 0; i < NumOfDef-1; i++)
	{
		tmp[i].operator=(Def[i]);
	}
	Def = new Definition[NumOfDef];
	for (int i = 0; i < NumOfDef-1; i++)
	{
		Def[i].operator=(tmp[i]);
	}
	Def[NumOfDef - 1].operator=(x);
	return (*this);
}
Dictionary& Dictionary::NewDefinition(const Dictionary& x)
{
	String tmp;
	cout << "Enter A The Name of the Definition to add a new definition" << endl;
	tmp.operator >> (tmp);
	for (int i = 0;i < NumOfDef;i++)
	{
		if (CheckDefinition(tmp) == 1)
		{
			cout << "Enter A new Translate For your Defintion" << endl;
			String tmp1;
			tmp1.operator >> (tmp1);
			this->Def[i].operator+=(tmp1);
		}
	}
	return *this;
}
int Dictionary:: CheckDefinition (const String x)
{
	for (int i = 0;i < NumOfDef;i++)
	{
		if (this->Def[i].Word != x)
		{
			return 0;
		}
	}
	return 1;
}
Dictionary& Dictionary:: FindDefWord(char x[])
{
	for (int i = 0; i < NumOfDef; i++)
	{
		Def[i].FindWord(x);
	}
	return (*this);
}
Dictionary& Dictionary::AddDefinition(const Dictionary& x) 
{
	Definition tmp;
	(*Def).AddDefinition(tmp);
	(this)->operator+=(tmp);
	return (*this);
}
void Dictionary::EqaulDefines()
{
	for (int i = 0;i < NumOfDef;i++)
	{
		for (int j = 0;j < NumOfDef;j++)
		{
			if (Def[i].operator==(Def[j])&&i!=j)
			{
				Def[i].operator<<(Def[i]);
			}
		}
	}
}