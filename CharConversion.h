#ifndef CHAR_CONVERSION_H

#include <tchar.h>
#include <string.h>
#include <stdlib.h>

#include <Windows.h>

#include <locale>
#include <codecvt>
#include <string>


class CharConversion {
	
private:
	wchar_t * storedString;

	void init();
	
public:
	static char * convert(wchar_t * str)
	{
		int length = WideCharToMultiByte(CP_UTF8, 0, str, wcslen(str), 0, 0, NULL, NULL);
		char * output_buffer = new char [length];
		WideCharToMultiByte(CP_UTF8, 0, str, wcslen(str), output_buffer, length, NULL, NULL);
		output_buffer[length] = '\0';
		return output_buffer;
	}
	
	static wchar_t * convert(char * str)
	{	
		int length = MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), 0, 0);
		wchar_t * output_buffer = new wchar_t [length];
		MultiByteToWideChar(CP_UTF8, 0, str, strlen(str), output_buffer, length);
		output_buffer[length] = '\0';
		return output_buffer;
	}

	static std::string convert(std::wstring str)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		return converter.to_bytes(str);
	}

	static std::wstring convert(std::string str)
	{
		std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		return converter.from_bytes(str);
	}

	CharConversion();
	CharConversion(wchar_t * str);
	CharConversion(char * str);
	
	void clear();
	void setString(wchar_t * str);
	void setString(char * str);
	void append(wchar_t * str);
	void append(char * str);
	wchar_t * concat(wchar_t * str);
	char * concat(char * str);
	wchar_t * subString(int pos, int length);
	wchar_t * getString();

};

#define CHAR_CONVERSION_H
#endif //CHAR_CONVERSION_H