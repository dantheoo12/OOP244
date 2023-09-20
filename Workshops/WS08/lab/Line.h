#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		using LblShape::LblShape;
		Line();
		Line(const char* label, const int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // LINE_H