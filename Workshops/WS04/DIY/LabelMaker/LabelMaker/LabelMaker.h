#ifndef LABELMAKER_H
#define LABELMAKER_H

#include "Label.h"

namespace sdds {
	class LabelMaker {
		Label* m_labels;
		int m_noOfLabels;
	public:
		// creates LabelMaker with size noOfLabels
		LabelMaker(int noOfLabels);
		// reads labels from cin and stores data in labels
		void readLabels();
		// displays labels in lables
		void printLabels() const;
		// deallocates memory for labels array
		~LabelMaker();
	};
}
#endif // LABELMAKER_H
