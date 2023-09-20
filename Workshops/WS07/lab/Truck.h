#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

using namespace std;

namespace sdds {
	class Truck : public MotorVehicle {
		double m_maxCapacity;
		double m_currentLoad;
	public:
		using MotorVehicle::MotorVehicle;
		Truck(const char*, int, double, const char*);
		// add cargo to truck if there is capacity
		// return true if cargo was added successfully, false otherwise
		bool addCargo(double);
		// removes all cargo from truck
		// if any cargo was removed, return true, false otherwise
		bool unloadCargo();
		// writes to ostream in the format 
		// | [YEAR] | [PLATE] | [ADDRESS] | [CURRENT_CARGO]/[CAPACITY]
		ostream& write(ostream&)const;
		// reads from istream in the format
		/*	Built year : [USER TYPES HERE]
			License plate : [USER TYPES HERE]
			Current location : [USER TYPES HERE]
			Capacity : [USER TYPES HERE]
			Cargo : [USER TYPES HERE]*/
		istream& read(istream&);
		friend istream& operator>>(istream&, Truck&);
		friend ostream& operator<<(ostream&, Truck);

	};
	// uses read() to take input from istream
	istream& operator>>(istream&, Truck&);
	// uses write() to output to ostream
	ostream& operator<<(ostream&, Truck);
}
#endif