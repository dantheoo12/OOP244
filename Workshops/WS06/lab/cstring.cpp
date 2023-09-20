#include "cstring.h"
namespace sdds {
	// Copies the source character string into the destination
	void strCpy(char* des, const char* src)
	{
		if (src != nullptr) // ensure there is a string at src
		{
			char* ptr = des;
			while (*src != '\0')
			{
				*ptr = *src;
				ptr++, src++;
			}
			*ptr = '\0'; // null terminate des after copying all of src
		}
	}
	// returns the length of the C-string in characters
	int strLen(const char* s)
	{
		int len = 0;

		while (*s != '\0')
		{
			s++, len++;
		}

		return len;
	}
	// Concantenates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		// get pointer of \0 of des
		while (*des != '\0')
			des++;

		while (*src != '\0')
		{
			*des = *src;
			des++, src++;
		}
		*des = '\0';
	}
}