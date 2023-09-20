#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width, m_height;
	public:
		using LblShape::LblShape;
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif
