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

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		if (src != nullptr) // ensure there is a string at src
		{
			while (*src != '\0' && len != 0)
			{
				*des = *src;
				des++, src++;
				len--;
			}
			if (strLen(src) < len)
				*des = '\0';
		}
	}

	// Compares two C-strings 
	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') // stop iterating if *s1 and *s2 are different or if at end of s1 or s2
		{
			s1++, s2++;
		}

		return *s1 - *s2;
	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && len != 1) // strCmp condition with len
			// len != 1 to compare len characters rather than len + 1 for zero indexing
		{
			s1++, s2++, len--;
		}

		return *s1 - *s2;
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

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		while (*str1 != '\0')
		{
			if (*str1 == *str2) // *str1 matches first char of str2
			{
				if (strnCmp(str1, str2, strLen(str2)) == 0)
				{
					return str1;
				}
			}
			str1++;
		}
		return nullptr;
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