#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {
	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid() const {
		bool valid = true;
		int i = 0;

		// validate title
		if (m_title[0] == '\0') {
			valid = false;
		}

		// validate items array and each item in array
		if (m_items != nullptr) {
			for (i = 0; i < m_noOfItems; i++) {
				if (!m_items[i].isValid()) {
					valid = false;
				}
			}
		}
		else {
			valid = false;
		}

		return valid;
	}

	double Bill::totalTax() const {
		int i = 0;
		float taxTotal = 0;
		for (i = 0; i < m_noOfItems; i++) {
			taxTotal += m_items[i].tax();
		}
		return taxTotal;
	}

	double Bill::totalPrice() const {
		int i = 0;
		float priceTotal = 0;
		for (i = 0; i < m_noOfItems; i++) {
			priceTotal += m_items[i].price();
		}
		return priceTotal;
	}

	void Bill::Title() const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| ";
			cout.width(36);
			cout << left << m_title << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer() const {
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid()) {
			// print tax
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << right << totalTax() << " |" << endl;
			// print price
			cout << "|              Total Price: ";
			cout.width(10);
			cout.precision(2);
			cout << right << totalPrice() << " |" << endl;
			// print total
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.precision(2);
			cout << right << totalPrice() + totalTax() << " |" << endl;
			cout.unsetf(ios::fixed); // remove formatting
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		int i = 0;
		if (title == nullptr || noOfItems <= 0) {
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[noOfItems];
			// set all items in m_items array to empty
			for (i = 0; i < noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}
	
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool added = false;
		
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			added = true;
		}
		return added;
	}

	void Bill::display() const {
		int i = 0;
		Title(); // print title
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer(); // print footer
	}

	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}