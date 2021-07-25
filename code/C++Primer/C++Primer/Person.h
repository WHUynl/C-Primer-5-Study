#pragma once

#include <iostream>
#include <string>

using namespace std;


int test4 = 0;
class Person {
private:
	string name;
	string address;
public:
	string getName() const { return name; }
	string getAddress() const { return address; }
	
	Person() = default;

	Person(int test) {
		int k = 1 + ::test4;
	}

	Person(string n, string add) :name(n), address(add) {

	}

	Person(istream& is);


	friend istream& read(istream& is, Person& p);
	friend ostream& print(ostream& os, const Person& p);

};

 istream& read(istream& is, Person& p);
 ostream& print(ostream& os, const Person& p);
