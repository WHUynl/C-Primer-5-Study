#pragma once
#include<string>
#include<iostream>
using namespace std;
class Sales_data
{
public:
	Sales_data():bookNo("") {  }
	Sales_data(const Sales_data&);
	Sales_data& operator+=(const Sales_data&);
	friend ostream& operator<<(ostream&, const Sales_data&);
	friend istream& operator>>(istream&, Sales_data&);
	friend bool operator == (const Sales_data&, const Sales_data&);
	friend bool operator != (const Sales_data&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
	explicit operator string() const;
	
private:
	string bookNo;
	int units_sold = 0;
	double revenue = 0.0;
};


ostream& operator<<(ostream& os, const Sales_data& s) {
	os << s.bookNo << " " << s.units_sold << " " << s.revenue;
	return os;
}

istream& operator>>(istream& is, Sales_data& s) {
	double price;
	is >> s.bookNo >> s.units_sold >> price;
	if (is)//检查输入是否成功
		s.revenue = s.units_sold * price;
	else
		s = Sales_data();
	return is;
}

bool operator == (const Sales_data& l, const Sales_data& r) {
	return l.bookNo == r.bookNo &&
		l.revenue == r.revenue &&
		l.units_sold == r.units_sold;

}

bool operator != (const Sales_data& l, const Sales_data& r) {
	return !(l == r);
}

Sales_data operator+(const Sales_data& l, const Sales_data& r) {
	Sales_data tmp = l;
	tmp += r;
	return tmp;
}