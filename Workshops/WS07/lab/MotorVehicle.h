#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <iostream>

#define LICENSE_PLATE_LENGTH 9
#define ADDRESS_LENGTH 64

using namespace std;

namespace sdds {
	class MotorVehicle {
	private:
		char m_plateNumber[LICENSE_PLATE_LENGTH];
		char m_address[ADDRESS_LENGTH];
		int m_buildYear;
	public:
		// construct MotorVehicle with provided parameters for plate number and build year
		// default address is "Factory"
		// all data is assumed valid
		MotorVehicle(const char*, int); 
		// moves current m_address to address if they are different
		// prints in format |[LICENSE_PLATE]| |[CURRENT_ADDRESS] ---> [NEW_ADDRESS]|<ENDL>
		void moveTo(const char*);
		// outputs to os in the form | [YEAR] | [PLATE] | [ADDRESS]
		ostream& write(ostream&)const;
		// inputs to the current MotorVehicle via the output: 
			/*Built year : [USER TYPES HERE]
			License plate : [USER TYPES HERE]
			Current location : [USER TYPES HERE]*/
		istream& read(istream&);
		friend istream& operator>>(istream&, MotorVehicle&);
		friend ostream& operator<<(ostream&, MotorVehicle);
	};
	// uses read() to take input from istream
	istream& operator>>(istream&, MotorVehicle&);
	// uses write() to output to ostream
	ostream& operator<<(ostream&, MotorVehicle);
}
#endif
