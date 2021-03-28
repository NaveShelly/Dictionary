#include "Definition.h"
Definition::Definition()
{
	NumOfTranslate = 0;
	//Define = new String*[1];
}
Definition::Definition(const Definition& x)
{
	this->operator=(x);
}
Definition::~Definition()
{
	for (int i = 0; i < NumOfTranslate; i++)
	{
		this->Define[i].~String();
	}
}
Definition& Definition :: operator=(const Definition& x)
{
	this->Word = x.Word;
	this->NumOfTranslate = x.NumOfTranslate;
	this->Define = x.Define;
	return *this;
}

bool Definition::operator==(const Definition& x)const
{
	if (NumOfTranslate != x.NumOfTranslate)
		return 0;
	for (int i = 0; i < Word.length ; i++)
	{
		if (Word.operator!=(x.Word))
			return 0;
	}
	for (int i = 0; i < NumOfTranslate; i++)
	{
		for (int j = 0; j < Word.length; j++)
		{
			if ((Define)!=x.Define)
				return 0;
		}

	}
	return 1;
}
bool Definition::operator!=(const Definition & x) 
{
	if(!(this->operator==(x)))
	return true;
}
void Definition::operator<<(const Definition & x) const
{
	cout << "You Have " << this->NumOfTranslate<< " Number of Definitions" << endl;
	Word.operator<<(Word);
	for (int i = 0; i < NumOfTranslate; i++)
	{
		Define[i].operator<<(Define[i]);
	}
}
Definition& Definition:: operator >> (const Definition& x)
{
	Word.operator>>(Word);
	cout<< "How Many Definitions your Word Have" << endl;
	cin >> NumOfTranslate;
	Define = new String[NumOfTranslate];
	getchar();
	for (int i = 0; i < NumOfTranslate; i++)
	{
		Define[i].operator >> (Define[i]);
	}
	cout << "Your Defintion is Succsses created" << endl;
	return (*this);
}
Definition& Definition:: operator-=(const int x)
{
	String *tmp;
	tmp = new String[NumOfTranslate - 1];
	for (int i = 0; i < NumOfTranslate; i++)
	{
		if (i != x)
		{
			tmp[i].operator= (Define[i]);
		}
	}
	Define= new String[NumOfTranslate - 1];
	for (int i = 0; i < NumOfTranslate-1; i++)
	{
		Define[i].operator= (tmp[i]);
	}
	NumOfTranslate--;
	return (*this);
}
Definition& Definition:: operator+=(const String& x)
{
	for (int i = 0; i < NumOfTranslate; i++)
	{
		if ((Word.operator==(x))==1|| (Define[i].operator==(x))==1)
		{
			return (*this);
		}
	}
	String *tmp;
	NumOfTranslate++;
	tmp = new String[NumOfTranslate];
	for (int i = 0; i < NumOfTranslate-1; i++)
	{
		tmp[i].operator=(Define[i]);
	}
	Define = new String[NumOfTranslate];
	for (int i = 0; i < NumOfTranslate-1; i++)
	{
		Define[i].operator=(tmp[i]);
	}
	Define[NumOfTranslate - 1].operator=(x);
	return *this;
}
Definition& Definition::FindWord(const char x[]) 
{
	char *tmp;
	tmp = GetWord();
	for (int i = 0;x[i]!='\0'; i++)
	{
		if (tmp[i]!=x[i])
		{
			cout << "There Are No such A Word" << endl;
			return *this;
		}
	}
	for (int i = 0;i < NumOfTranslate;i++)
	{
		cout << "The Definitions of the Words Are:" << endl;
		Define[i].operator<<(Define[i]);
	}
	return *this;
}
char* Definition::GetWord()
{
	String tmp(Word);
	return tmp.Word;
}
Definition& Definition::AddDefinition(Definition& tmp)
{
	tmp.operator >> (tmp);
	return tmp;
}