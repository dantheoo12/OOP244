 #define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {
	const double PI = 3.14159265;

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty() const {
		return m_contentVolume < 0.00001;
	}

	bool Canister::hasSameContent(const Canister& C)const {
		return strCmp(C.m_contentName, m_contentName) == 0;
	}

	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && m_usable == true) {
			if (m_contentName != nullptr) {
				m_contentName[0] = '\0';
				delete[] m_contentName;
			}
			m_contentName = nullptr;
			m_contentName = new char[strLen(Cstr) + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	Canister::Canister() {
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		if (height >= 10.0 && height <= 40.0 &&
			diameter >= 10.0 && diameter <= 30.0) {
			m_height = height;
			m_diameter = diameter;
			setName(contentName);
		}
		else {
			m_usable = false;
		}
	}

	Canister::~Canister() {
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	double Canister::capacity() const {
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	double Canister::volume() const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr) {
			m_usable = false;
		}
		else if (m_contentName == nullptr) {
			setName(contentName);
		}
		else if (strCmp(m_contentName, contentName) != 0) {
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		if (m_usable && 
			quantity > 0 && 
			(quantity + m_contentVolume) <= capacity()) {
				m_contentVolume += quantity;
		}
		else {
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C) { // *this is the receiver, C is pourer
		if (C.m_usable == true && volume() < capacity()) { // pourer is usable and receiver is not full
			// receiver is empty
			if (isEmpty()) { 
				if (C.volume() > capacity()) { // pourer has more than receiver capacity
					m_contentVolume = capacity(); // fill receiver to capacity
					C.m_contentVolume -= m_contentVolume; // reduce pourer by poured amount
				}
				else { // pourer has less liquid than receiver capacity
					pour(C.volume()); // pour all of pourer into receiver
					C.m_contentVolume = 0.0; // set pourer to empty
				}
				setName(C.m_contentName); // change receiver name to pourer name
			}
			// receiver has contents
			else { 
				// pourer has more than empty space in receiver (capacity - current volume)
				if (C.volume() > capacity() - m_contentVolume) { 
					C.m_contentVolume -= (capacity() - m_contentVolume); // reduce pourer by empty space in receiver
					m_contentVolume = capacity(); // fill receiver to capacity
				}
				// pourer contains less than receiver empty space (capacity - current volume)
				else { 
					pour(C.m_contentVolume);
					C.m_contentVolume = 0.0;
				}

				// check if contents of receiver are usable
				if (strCmp(m_contentName, C.m_contentName) != 0) {// pourer had different contents from receiver
					m_usable = false; // receiver is unusable (mixed contents)
					delete[] m_contentName;
					m_contentName = nullptr;
				}
				else {
					m_usable = true; // receiver is usable (same contents)
				}
			}
		}
		return *this;
	}

	std::ostream& Canister::display()const {
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity();
		cout << "cc (" << m_height << "x" << m_diameter << ") Canister";
		if (!m_usable) {
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr) {
			cout << " of ";
			cout.width(7);
			cout << m_contentVolume << "cc   " << m_contentName;
		}
		return cout;
	}
}