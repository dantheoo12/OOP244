#ifndef MARK_H
#define MARK_H

namespace sdds {
	class Mark {
		int m_mark;
		bool m_valid;
	public:
		/*Mark 	Grade 	Scale 4 mark
			0 < = Mark < 50 	F 	0.0
			50 < = Mark < 60 	D 	1.0
			60 < = Mark < 70 	C 	2.0
			70 < = Mark < 80 	B 	3.0
			80 < = Mark < = 100 	A 	4.0
		*/

		// constructor, initialize m_mark to 0
		Mark();
		// constructor, initialize m_mark to 0 if mark not within 0 and 100 inclusive
		Mark(int);
		// cast to int
		// output m_mark or 0 if invalid
		operator int() const;
		// add mark to m_mark
		// return reference to mark
		Mark& operator +=(int);
		// assign mark to m_mark
		// can overwrite an invalid mark
		Mark& operator =(int);
		// cast to double (appropriate GPA scale)
		operator double() const;
		// cast to character (approprate grade value)
		// invalid will output 'X'
		operator char() const;
		friend int& operator +=(int&, Mark);
	};
	// add int value of mark to num
	// invalid value adds 0
	int& operator +=(int&, Mark);
}

#endif