#ifndef LBLSHAPE_H
#define LBLSHAPE_H

#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label;
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(LblShape&) = delete;
		LblShape& operator=(LblShape&) = delete;
		void getSpecs(std::istream& istr);
		void setLabel(const char* label);
	};
}
#endif // LBLSHAPE_H