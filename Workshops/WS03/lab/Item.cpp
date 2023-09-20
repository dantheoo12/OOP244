#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
	void Item :: setName(const char* name) {
		strnCpy(m_itemName, name, 20);
	}

	void Item::setEmpty() {
		m_itemName[0] = '\0';
		m_price = 0.0;
		m_taxed = false;
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (name == nullptr || price <= 0) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price() const {
		return m_price;
	}

	double Item::tax() const {
		double tax = 0;

		if (m_taxed) {
			tax = m_price * 0.13;
		}

		return tax;
	}

	bool Item::isValid() const {
		return m_price != 0 && m_itemName != nullptr; // price will only be 0 in an empty state
	}

	void Item::display() const {
		if (isValid()) {
			cout << "| ";
			// print item name
			cout.fill('.');
			cout.width(20);
			cout << left << m_itemName << " | ";
			cout.unsetf(ios::fixed); // remove item name formatting
			// print item price
			cout.fill(' ');
			cout.width(7);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << right << m_price << " | ";
			cout.unsetf(ios::fixed); // remove price formatting
			// print taxed
			if (m_taxed) {
				cout << "Yes";
			}
			else {
				cout << "No ";
			}
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}