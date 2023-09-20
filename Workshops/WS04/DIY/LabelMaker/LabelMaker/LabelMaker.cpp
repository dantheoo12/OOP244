#include <iostream>
#include "LabelMaker.h"

using namespace std;

namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		m_labels = new Label[noOfLabels];
		m_noOfLabels = noOfLabels;
	}

	void LabelMaker::readLabels() {
		int i;
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for (i = 0; i < m_noOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl << "> ";
			m_labels[i].readLabel();
		}
	}

	void LabelMaker::printLabels() const {
		int i;
		for (i = 0; i < m_noOfLabels; i++) {
			m_labels[i].printLabel();
			cout << endl;
		}
	}

	LabelMaker::~LabelMaker() {
		delete[] m_labels;
		m_labels = nullptr;
	}
}