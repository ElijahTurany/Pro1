/*
* CHANGELOG:
* 2023.04.13 Alexi Brooks - Created
*/
#include <iostream>
#include <string>
#include <vector>
#include "RotatableTrio.h"
using namespace std;
//Main function, provided for testing and guidance.
//Do not modify this function!
int main() {
	cout << "Running tests of the RotatableTrio class..." << endl;
	cout << "Test 1: Constructor does not crash: ";
	try {
		RotatableTrio<int> a{ 5,6,9 };
		cout << "SUCCESS." << endl;
	}
	catch (...) {
		cout << "FAILED." << endl;
	}
	cout << "Test 2: Getters give correct values: ";
	RotatableTrio<string> b{ "one","two","three" };
	if (b.getMiddle() != "two") {
		cout << "FAILED.";
		cout << " (Expected: \"two\". Actual: " << b.getMiddle() << ")";
		cout << endl;
	}
	else if (b.getFirst() != "one") {
		cout << "FAILED.";
		cout << " (Expected: \"one\". Actual: " << b.getFirst() << ")";
		cout << endl;
	}
	else if (b.getLast() != "three") {
		cout << "FAILED.";
		cout << " (Expected: \"three\". Actual: " << b.getLast() << ")";
		cout << endl;
	}
	else {
		cout << "SUCCESS." << endl;
	}
	cout << "Test 3: (9,4,200) Rotates as expected: ";
	RotatableTrio<int> c{ 9,4,200 };
	c.rotate();
	if (c.getMiddle() != 9) {
		cout << "FAILED.";
		cout << " (Expected: 9. Actual: " << c.getMiddle() << ")";
		cout << endl;
	}
	else if (c.getFirst() != 200) {
		cout << "FAILED.";
		cout << " (Expected: 200. Actual: " << c.getFirst() << ")";
		cout << endl;
	}
	else if (c.getLast() != 4) {
		cout << "FAILED.";
		cout << " (Expected: 4. Actual: " << c.getLast() << ")";
		cout << endl;
	}
	else {
		cout << "SUCCESS." << endl;
	}
	cout << "Test 4: Setters throw exception: ";
	RotatableTrio<double> d{ 3.3,5.78,9.222 };
	try {
		d.setFirst(30);
		d.setMiddle(-6.1);
		d.setLast(99.09);
		cout << "FAILED." << endl;
	}
	catch (...) {
		cout << "SUCCESS." << endl;
	}
}