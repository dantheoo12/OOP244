#ifndef LABEL_H
#define LABEL_H

#include <iostream>
#include <iomanip>
#include "cstring.h"

namespace sdds {
	class Label {
		// frame "AbCdEfGh" stored in this format:
		/*
		AbbbbbbbbbbbbbbbbbbbbbbbbbC
		h                         d
		h                         d
		h                         d
		GfffffffffffffffffffffffffE
		*/
		char m_frame[9];
		char* m_content;

	public:
		// creates label and defaults to "+-+|+-+|"
		Label(); 
		// creates label and sets the frame to frameArg
		Label(const char* frameArg);
		// creates label and sets frame to frameArg and content to content
		Label(const char* frameArg, const char* content);
		// deallocates memory for the label content
		~Label();
		// reads label from input and stores to content
		void readLabel();
		// displays the label by printing the frame around the content
		// no newlone added after the end(?)
		// returns cout
		std::ostream& printLabel()const;
	};
} 
#endif // LABEL_H