#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds {
	// Copies the source character string into the destination
	void strCpy(char* des, const char* src);
	// returns the length of the C-string in characters
	int strLen(const char* s);
	// Concantenates "src" C-string to the end of "des"
	void strCat(char* des, const char* src);
}
#endif // !SDDS_CSTRING_H_



