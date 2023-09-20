#ifndef CALORIELIST_H
#define CALORIELIST_H

#include "Food.h"
namespace sdds {
	class CalorieList {
		Food* f_items;
		int f_noOfItems;
		int f_itemsAdded;
		int totalCalories() const;
		void header() const;
		void footer() const;
		void setEmpty();
		bool isValid() const;
	public:
		void init(int noOfItems);
		bool add(const char* foodName, int calories, int timeEaten);
		void display() const;
		void deallocate();
	};
}
#endif // CALORIELIST_H