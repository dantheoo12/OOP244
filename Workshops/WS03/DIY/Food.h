#ifndef FOOD_H
#define FOOD_H

namespace sdds {
	class Food {
		char f_foodname[31];
		int f_calories;
		int f_timeEaten;

	public:
		// set food to empty state
		void setEmpty(); 
		// set food item to values
		void set(const char* name, int calories, int timeEaten);
		// return calories of item
		double calories() const;
		// display a food item in a single line format
		void display() const;
		// return true if item is a valid food item, else return false
		bool isValid() const;
	};
}
#endif // FOOD_H