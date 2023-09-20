#include <iostream>
#include "Line.h"

namespace sdds {
	// Line constructors
	Line::Line() : LblShape() {
		m_length = 0;
	}
	Line::Line(const char* label, const int length) : LblShape(label) {
		m_length = length;
	}

	// Line member functions
	void Line::getSpecs(std::istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_length;
		istr.ignore(1000, '\n');
	}
	void Line::draw(std::ostream& ostr)const {
		if (m_length > 0 && label() != nullptr) {
			ostr << label() << std::endl;
			for (int i = 0; i < m_length; i++) {
				ostr << '=';
			}
		}
	}
}