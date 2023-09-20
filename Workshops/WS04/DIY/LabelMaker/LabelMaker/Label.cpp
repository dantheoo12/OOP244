#include "Label.h"

using namespace std;
namespace sdds {
	Label::Label() {
		strnCpy(m_frame, "+-+|+-+|", 8);
		m_content = nullptr;
	}

	Label::Label(const char* frameArg) {
		strnCpy(m_frame, frameArg, 8);
		m_content = nullptr;
	}

	Label::Label(const char* frameArg, const char* content) {
		strnCpy(m_frame, frameArg, 8);
		// set size to 71 if length is greater than 71, otherwise set it to length + 1
		m_content = new char[strLen(content) > 70 ? 70 + 1 : strLen(content) + 1];
		// if content length > 70, copy first 70 characters, otherwise copy the entire content string
		strnCpy(m_content, content, strLen(content) > 70 ? 70 : strLen(content));
	}

	Label::~Label() {
		delete[] m_content;
		m_content = nullptr;
	}

	void Label::readLabel() {
		char content[71];
		cin.getline(content, 71);
		m_content = new char[strLen(content) + 1];
		strnCpy(m_content, content, 70);
	}

	std::ostream& Label::printLabel() const {
		if (m_content != nullptr) {
			// LINE 1
			cout << m_frame[0] << setw(strLen(m_content) + 3) << setfill(m_frame[1]) << m_frame[2] << endl;
			// LINE 2
			cout << m_frame[7] << setw(strLen(m_content) + 3) << setfill(' ') << m_frame[3] << endl;
			// LINE 3 (Content line)
			cout << m_frame[7] << ' ' << m_content << ' ' << m_frame[3] << endl;
			// LINE 4 (same as line 2)
			cout << m_frame[7] << setw(strLen(m_content) + 3) << setfill(' ') << m_frame[3] << endl;
			// LINE 5
			cout << m_frame[6] << setw(strLen(m_content) + 3) << setfill(m_frame[5]) << m_frame[4];
		}
		return cout;
	}
}