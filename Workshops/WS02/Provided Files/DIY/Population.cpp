#include <iostream>
#include "File.h"
#include "Population.h"
#include "cstring.h"

using namespace std;
namespace sdds {

	int noOfCodes;
	PostalPopulation* codes;

	void sort() {
		int i, j;
		PostalPopulation temp;
		for (i = noOfCodes - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (codes[j].pop > codes[j + 1].pop) {
					temp = codes[j];
					codes[j] = codes[j + 1];
					codes[j + 1] = temp;
				}
			}
		}
	}

	bool load(const char* filename) {
		bool ok = false;
		int i = 0;
		if (openFile(filename)) {
			noOfCodes = noOfRecords();
			codes = new PostalPopulation[noOfCodes];
			for (i = 0; i < noOfCodes; i++) {
				load(codes[i]);
			}
			if (i != noOfCodes) {
				cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
			}
			else {
				ok = true;
			}
		}
		else {
			cout << "Could not open data file: " << filename << endl;
		}
		closeFile();
		return ok;
	}

	bool load(PostalPopulation& record) {
		bool ok = false;
		char code[10];
		if (read(code) && read(record.pop)) {
			record.code = new char[strLen(code) + 1];
			strCpy(record.code, code);
			ok = true;
		}
		return ok;
	}

	void display() {
		int i = 0, totalPop = 0;
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		sort();
		for (i = 0; i < noOfCodes; i++) {
			cout << i + 1 << "- ";
			display(codes[i]);
			totalPop += codes[i].pop;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totalPop << endl;
	}

	void display(const PostalPopulation& record) {
		cout << record.code << ":  " << record.pop << endl;
	}

	void deallocateMemory() {
		int i = 0;
		for (i = 0; i < noOfCodes; i++) {
			delete[] codes[i].code;
			codes[i].code = nullptr;
		}
		delete[] codes;
		codes = nullptr;
	}
}