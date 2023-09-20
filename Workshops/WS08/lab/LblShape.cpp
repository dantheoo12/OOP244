#define _CRT_SECURE_NO_WARNINGS
#define MAX_LABEL_SIZE 100

#include <iostream>
#include <string.h>
#include <string>
#include "LblShape.h"

namespace sdds {
	// LblShape protected functions
	const char* LblShape::label()const {
		return m_label;
	}

	// LblShape public functions
	LblShape::LblShape() {
		m_label = nullptr;
	} 
	LblShape::LblShape(const char* label) {
		setLabel(label);
	}
	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}
	void LblShape::getSpecs(std::istream& istr) {
		char label[MAX_LABEL_SIZE];
		istr.getline(label, MAX_LABEL_SIZE, ',');
		if (m_label != nullptr) {
			delete[] m_label;
			m_label = nullptr;
		}
		setLabel(label);
	}
	void LblShape::setLabel(const char* label) {
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
}