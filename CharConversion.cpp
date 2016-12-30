#include "CharConversion.h"

void CharConversion::init()
{
	storedString = NULL;
}

CharConversion::CharConversion()
{
	init();
}

CharConversion::CharConversion(wchar_t * str)
{
	init();
	setString(str); 
}

CharConversion::CharConversion(char * str)
{
	init();
	setString(str); 
}

void CharConversion::clear()
{
	if(storedString)
	{
		delete[] storedString;
	}
}
	
void CharConversion::setString(wchar_t * str)
{
	int length = wcslen(str);
	if(!length)
	{
		storedString = NULL;
		return;
	}
	clear();
	storedString = new wchar_t[length+1];
	wcsncpy(storedString, str, length);
	storedString[length] = '\0';
}

void CharConversion::setString(char * str)
{
	setString(convert(str));
}

wchar_t * CharConversion::concat(wchar_t * str)
{
	int length = wcslen(str);
	if(!length) 
		return storedString;
	
	length += wcslen(storedString);
	wchar_t * tempt = new wchar_t[length+1];
	wcscpy(tempt, storedString);
	wcscat(tempt, str);
	tempt[length] = '\0';
	return tempt;
}
char * CharConversion::concat(char * str)
{
	return convert(concat(convert(str)));
}

void CharConversion::append(wchar_t * str)
{
	int length = wcslen(str);
	if(!length) 
		return;

	setString(concat(str));
}

void CharConversion::append(char * str)
{
	append(convert(str));
}

wchar_t * CharConversion::subString(int pos, int length)
{
	wchar_t *tempt = new wchar_t[length+1];
	memcpy(tempt, storedString, length);
	tempt[length] = '\0';
	return tempt;
}

wchar_t * CharConversion::getString()
{
	return subString(0, wcslen(storedString));
}
