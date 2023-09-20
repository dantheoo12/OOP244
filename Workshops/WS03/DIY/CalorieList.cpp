#include <iostream>
#include "cstring.h"
#include "CalorieList.h"

namespace sdds {
	void CalorieList::setEmpty() {
		f_noOfItems = 0;
		f_itemsAdded = 0;
		f_items = nullptr;
	}

	bool CalorieList::isValid() const {
		bool valid = true;
		int i = 0;

		if (f_items != nullptr) {
			for (i = 0; i < f_noOfItems; i++) {
				if (!f_items[i].isValid()) {
					valid = false;
				}
			}
		}
		else {
			valid = false;
		}
		return valid;
	}

	int CalorieList::totalCalories() const {
		int i = 0, calories = 0;
		for (i = 0; i < f_noOfItems; i++) {
			calories += f_items[i].calories();
		}
		return calories;
	}

	void CalorieList::header() const {
		std::cout << "+----------------------------------------------------+" << std::endl;
		if (isValid()) {
			std::cout << "|  Daily Calorie Consumption                         |" << std::endl;
		}
		else {
			std::cout << "| Invalid Calorie Consumption list                   |" << std::endl;
		}
		std::cout << "+--------------------------------+------+------------+" << std::endl;
		std::cout << "| Food name                      | Cals | When       |" << std::endl;
		std::cout << "+--------------------------------+------+------------+" << std::endl;
	}

	void CalorieList::footer() const {
		std::cout << "+--------------------------------+------+------------+" << std::endl;
		if (isValid()) {
			std::cout << "|    Total Calories for today: ";
			std::cout.width(8);
			std::cout << std::right << totalCalories();
			std::cout << " |            |" << std::endl;
		}
		else {
			std::cout << "|    Invalid Calorie Consumption list                |" << std::endl;
		}
		std::cout << "+----------------------------------------------------+" << std::endl;
	}

	void CalorieList::init(int noOfItems) {
		int i = 0;
		f_itemsAdded = 0;
		f_noOfItems = noOfItems;
		f_items = new Food[noOfItems];
		for (i = 0; i < noOfItems; i++) {
			f_items[i].setEmpty();
		}
	}

	bool CalorieList::add(const char* foodName, int calories, int timeEaten) {
		bool added = false;
		if (f_itemsAdded < f_noOfItems) {
			f_items[f_itemsAdded].set(foodName, calories, timeEaten);
			f_itemsAdded++;
			added = true;
		}
		return added;
	}

	void CalorieList::display() const {
		int i = 0;
		header();
		for (i = 0; i < f_noOfItems; i++) {
			f_items[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		delete[] f_items;
		f_items = nullptr;
	}
}