#include "String.h"
String::String()
{
	Word = NULL;
	length = 0;
}
//String::~String()
//{
//	delete Word;
//	cout << "String Deleted" << endl;
//}
String& String :: operator=(const String& x)
{
	length = x.length;
	Word = new char[(length) + 1];
	for (int i = 0; i < length + 1; i++)
	{
		Word[i] = x.Word[i];
	}
	return *this;
}
bool String::operator==(const String & x) const
{
	for (int i = 0; i < length; i++)
		if (this->length != x.length || x.Word[i] != this->Word[i])
			return false;
		else return true;
}
bool String::operator!=(const String & x) const
{
	if ((*this).operator==(x)==false)
	{
		return true;
	}
	else return false;
}
void String::operator<<(const String & x) const
{
	for (int i = 0; i < length; i++)
	{
		cout << Word[i];
	}
}

String& String::operator >> (const String &x)
{
	int counter = 1;
	char temp[80];
	int answer=0;
	while (answer != 1)
	{
		cout << "Enter illgeal Definition" << endl;
		cin >> temp;
		for (int i = 0; temp[i] != '\0'; i++)
		{
			counter++;
			if (temp[i + 1] == '\n')
				temp[i + 1] = '\0';
		}
		answer = FixWord(temp);
	}
	setlength(counter);
	Word = new char[length];
	for (int i = 0; temp[i]!='\0'; i++)
	{
		Word[i]=temp[i];
	}
	return *this;
}
String& String::operator-=(const char x)
{
		int counter = 0;
		for (int i = 0; i < this->length; i++)
		{
			if (this->Word[i] != x)
				counter++;
		}
		char *temp = new char[counter];
		int tmp = 0;
		for (int i = 0; i < this->length; i++)
		{
			if (this->Word[i] != x)
			{
				temp[tmp] = Word[i];
				tmp++;
			}
		}
		this->Word = new char[counter];
		this->Word = temp;
		this->length = counter;
		return (*this);
}
String& String::operator+=(const char x)
{
	char* temp = new char[(this->length)+1];
	temp = this->Word;
	temp[length] = x;
	this->length = (this->length) + 1;
	this->Word = new char[(this->length)];
	for (int i = 0; i < length; i++)
	{
		this->Word[i] = temp[i];
	}
	return (*this);
}
char* String :: operator[](const int x)const
{
	return Word;
}
int String::getlength()const
{
	return length;
}
char* String::getstr()const
{
	return Word;
}
bool FixWord(char *x)
{
	int i = 0;
	while (x[i] != '\0')
	{
		if ((x[i] == ' '&&x[i] == ' ') || (x[i] == '.' && x[i] == '.') || (x[i] == ',' && x[i] == ','))
		{
			x[i] = '*';
		}
		i++;
	}
	char tmp[80];
	int j = 0;
	for (i = 0; x[i-1] != '\0'; i++)
	{
		if (x[i] != '*')
		{
			tmp[j] = x[i];
			j++;
		}
	}
	x = tmp;
	for (i = 0; x[i] != '\0'; i++)
	{
		if (x[0]<'A' || x[0]>'Z')
			return 0;
		if (i != 0 && x[i - 1] != ' '&&x[i - 1] != '.'&&x[i - 1] != ','&&(x[i]<'a'||x[i]>'z'))
			return 0;
		if (x[i] == ' ' || x[i] == '.' || x[i] == ',')
		{
			x[i + 1] = x[i + 1] + 32;
		}
	}
	return 1;
}
void String::setlength(int x)
{
	length = x;
}