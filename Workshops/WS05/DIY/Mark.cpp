#include "Mark.h"

namespace sdds {
	// constructor, initialize m_mark to 0
	Mark::Mark() {
		m_mark = 0;
		m_valid = true;
	}

	// constructor, initialize m_mark to 0 if mark not within 0 and 100 inclusive
	Mark::Mark(int mark) {
		if (mark >= 0 && mark <= 100) {
			m_mark = mark;
			m_valid = true;
		}
		else {
			m_mark = 0;
			m_valid = false;
		}
	}

	// cast to int
	// output m_mark or 0 if invalid
	Mark::operator int() const {
		return (m_mark);
	}

	// add mark to m_mark
	// return reference to mark
	Mark& Mark::operator +=(int mark) {
		if (m_valid) {
			m_mark += mark;
			// check value after adding
			if (m_mark > 100 || m_mark < 0) {
				m_mark = 0;
				m_valid = false;
			}
		}
		return *this;
	}

	// assign mark to m_mark
	// can overwrite an invalid mark
	Mark& Mark::operator =(int mark) {
		if (mark > 100 || mark < 0) {
			m_mark = 0;
			m_valid = false;
		}
		else {
			m_mark = mark;
			m_valid = true;
		}
		return *this;
	}

	// cast to double (appropriate GPA scale)
	Mark::operator double() const {
		double GPA;
		if (!m_valid) {
			GPA = 0.0;
		}
		else if (m_mark >= 0 && m_mark < 50) {
			GPA = 0.0;
		}
		else if (m_mark >= 50 && m_mark < 60) {
			GPA = 1.0;
		}
		else if (m_mark >= 60 && m_mark < 70) {
			GPA = 2.0;
		}
		else if (m_mark >= 70 && m_mark < 80) {
			GPA = 3.0;
		}
		else {
			GPA = 4.0;
		}
		return GPA;
	}

	// cast to character (approprate grade value)
	// invalid will output 'X'
	Mark::operator char() const {
		char grade;
		if (!m_valid) {
			grade = 'X';
		}
		else if (m_mark >= 0 && m_mark < 50) {
			grade = 'F';
		}
		else if (m_mark >= 50 && m_mark < 60) {
			grade = 'D';
		}
		else if (m_mark >= 60 && m_mark < 70) {
			grade = 'C';
		}
		else if (m_mark >= 70 && m_mark < 80) {
			grade = 'B';
		}
		else {
			grade = 'A';
		}
		return grade;
	}

	// add int value of mark to num
	// invalid value adds 0
	int& operator +=(int& num, Mark mark) {
		if (mark.m_valid) {
			num += mark.m_mark;
		}
		return num;
	}
}