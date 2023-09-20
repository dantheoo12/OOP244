#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Truck.h"

using namespace std;

namespace sdds {
	Truck::Truck(const char* plateNumber, int buildYear, double maxCapacity, const char* address) : 
		MotorVehicle(plateNumber, buildYear) {
		m_maxCapacity = maxCapacity;
		m_currentLoad = 0;
		moveTo(address);
	}
	bool Truck::addCargo(double cargo) {
		bool added = false;
		if (m_currentLoad < m_maxCapacity) {
			m_currentLoad += cargo;
			if (m_currentLoad > m_maxCapacity) { // too much was added, reduce back to max capacity
				m_currentLoad = m_maxCapacity;
			}
			added = true;
		}
		return added;
	}
	bool Truck::unloadCargo() {
		bool removed = false;
		if (m_currentLoad > 0) {
			m_currentLoad = 0;
			removed = true;
		}
		return removed;
	}
	ostream& Truck::write(ostream& os)const {
		MotorVehicle::write(os);
		os <<  " | " << m_currentLoad << '/' << m_maxCapacity;
		return os;
	}
	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_maxCapacity;
		in.ignore(1000, '\n');
		cout << "Cargo: ";
		in >> m_currentLoad;
		in.ignore(1000, '\n');
		return in;
	}
	istream& operator>>(istream& istr, Truck& truck) {
		truck.read(istr);
		return istr;
	}
	ostream& operator<<(ostream& ostr, Truck truck) {
		truck.write(ostr);
		return ostr;
	}
}