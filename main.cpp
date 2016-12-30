#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CharConversion.h"

int main()
{
	//simple testing functions
	CharConversion newCharConversion("the new string");
	CharConversion newWCharConversion(L"the new string");
	if(wcscmp(newCharConversion.getString(), newWCharConversion.getString()))
	{
		printf("test1 failed\n");
	}
	
	newCharConversion.append("123123213");
	newWCharConversion.setString(newWCharConversion.concat("123123213"));	
	if(wcscmp(newCharConversion.getString(), newWCharConversion.getString()))
	{
		printf("test2 failed\n");
	}

	char * charString = new char[5];
	strcpy(charString, "abcd");
	charString[4] = '\0';
	if(strcmp(charString, CharConversion::convert(CharConversion::convert(charString))))
	{
		printf("test3 failed\n");
	}

	return 0;
}