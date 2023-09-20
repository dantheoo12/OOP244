#include <iostream>
#include "cstring.h"
#include "Food.h"

namespace sdds {
	void Food::setEmpty() {
		f_foodname[0] = '\0';
		f_calories = 0;
		f_timeEaten = 0;
	}

	void Food:: set(const char* name, int calories, int timeEaten) {
		if (name != nullptr && calories > 0 && calories <= 3000 && timeEaten >= 1 && timeEaten <= 4) { // all values must be valid
			strnCpy(f_foodname, name, 30);
			f_calories = calories;
			f_timeEaten = timeEaten;
		}
		else {
			setEmpty();
		}
	}

	double Food::calories() const{
		return f_calories;
	}

	bool Food::isValid() const {
		// return true only if all conditions are true
		return f_calories > 0 && 
			f_calories <= 3000 && 
			f_foodname != nullptr && 
			f_timeEaten >= 1 && 
			f_timeEaten <= 4;
	}

	void Food::display() const {
		if (isValid()) {
			std::cout << "| ";
			// print food name
			// 30 spaces, left justified, padded with '.'
			std::cout.fill('.');
			std::cout.width(30);
			std::cout << std::left << f_foodname << " | ";
			std::cout.unsetf(std::ios::fixed); // reset formatting
			// print calories
			// 4 spaces, right justified, padded with ' '
			std::cout.fill(' ');
			std::cout.width(4);
			std::cout << std::right << f_calories << " | ";
			std::cout.unsetf(std::ios::fixed);
			// print time eaten
			// 10 spaces, left justified, padded with ' '
			switch (f_timeEaten) {
				case 1:
					std::cout << "Breakfast ";
					break;
				case 2:
					std::cout << "Lunch     ";
					break;
				case 3:
					std::cout << "Dinner    ";
					break;
				case 4:
					std::cout << "Snack     ";
					break;
			}
			std::cout << " |" << std::endl;
		}
		else {
			std::cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << std::endl;
		}
	}
}