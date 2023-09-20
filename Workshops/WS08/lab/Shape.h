#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& ostr) const = 0;
		virtual void getSpecs(std::istream& istr) = 0;
		virtual ~Shape();
	};
	// Global operator overloads
	std::ostream& operator<<(std::ostream& ostr, Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);
}
#endif // SHAPE_H
