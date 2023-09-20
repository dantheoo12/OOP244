#ifndef SEARCHNLIST_H
#define SEARCHNLIST_H

#include <iostream>
#include "Collection.h"

namespace sdds {
	template <typename T1, typename T2>
	bool search(Collection<T1>& collection, T1* items, int numItems, T2 key) {
		bool found = false;
		for (int i = 0; i < numItems; i++) {
			if (items[i] == key) {
				found = true;
				collection.add(items[i]);
			}
		}
		return found;
	}
	// In order for this function to work, T1 must have the equality operator '==' implemented in order
	// to compare it to the key.

	template <typename T>
	void listArrayElements(const char* title, const T* items, int numItems) {
		std::cout << title << std::endl;
		for (int i = 0; i < numItems; i++) {
			std::cout << i + 1 << ": " << items[i] << std::endl;
		}
	}
	// The requirements for the type in this function is that it must have the '<<' operator implemented
	// in order to be able to print to cout. The '<<' operator is implemented in the abstract ReadWrite class,
	// which is the base class of all of our data classes in this lab. 
}
#endif