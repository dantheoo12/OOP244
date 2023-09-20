#include <iostream>
#include "Shape.h"

namespace sdds {
	Shape::~Shape() {
		// do nothing
	}
	std::ostream& operator<<(std::ostream& ostr, Shape& shape) {
		shape.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	}
}