#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "Rectangle.h"

namespace sdds {
	// Rectangle constructors
	Rectangle::Rectangle() : LblShape() {
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
		m_width = width;
		m_height = height;
		if (m_height < 3 || m_width < (int)strlen(LblShape::label() + 2)) {
			m_width = 0;
			m_height = 0;
		}
	}

	// Rectangle member functions
	void Rectangle::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		istr.ignore(1000, ',');
		istr >> m_height;
		istr.ignore(1000, '\n');
	}
	void Rectangle::draw(std::ostream& ostr)const {
		if (label() != nullptr && m_width != 0 && m_height != 0) {
			// LINE 1
			ostr << '+';
			for (int i = 0; i < m_width - 2; i++) {
				ostr << '-';
			}
			ostr << '+' << std::endl;
			// LINE 2
			ostr << '|';
			ostr << std::setw(m_width - 2) << std::left << label(); // print label left justified in width - 2 
			ostr << '|' << std::endl;
			// LINE 3 ~ HEIGHT - 3 LINES
			for (int i = 0; i < m_height - 3; i++) {
				ostr << '|';
				for (int j = 0; j < m_width - 2; j++) {
					ostr << ' ';
				}
				ostr << '|' << std::endl;
			}
			// LAST LINE
			ostr << '+';
			for (int i = 0; i < m_width - 2; i++) {
				ostr << '-';
			}
			ostr << '+';
		}
	}
}