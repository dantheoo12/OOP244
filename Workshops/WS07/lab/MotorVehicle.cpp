#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "MotorVehicle.h"

using namespace std;

namespace sdds {
	MotorVehicle::MotorVehicle(const char* plateNumber, int buildYear) {
		strcpy(m_plateNumber, plateNumber);
		strcpy(m_address, "Factory");
		m_buildYear = buildYear;
	}
	void MotorVehicle::moveTo(const char* address) {
		if (strcmp(m_address, address)) { // address is different from current address
			cout << '|' << setw(8) << right << m_plateNumber << "| |" <<
				setw(20) << right << m_address << " ---> " <<
				setw(20) << left << address << '|' << endl;
				strcpy(m_address, address);
		}
	}
	ostream& MotorVehicle::write(ostream& os)const {
		os << "| " << m_buildYear << " | " << m_plateNumber << " | " << m_address;
		return os;
	}
	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> m_buildYear;
		in.ignore(1000, '\n');
		cout << "License plate: ";
		in >> m_plateNumber;
		in.ignore(1000, '\n');
		cout << "Current location: ";
		in >> m_address;
		in.ignore(1000, '\n');
		return in;
	}
	istream& operator>>(istream& istr, MotorVehicle& veh) {
		veh.read(istr);
		return istr;
	}
	ostream& operator<<(ostream& ostr, MotorVehicle veh) {
		veh.write(ostr);
		return ostr;
	}
}