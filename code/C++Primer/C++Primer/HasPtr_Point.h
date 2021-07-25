#pragma once
#include<string>
using namespace std;
class HasPtr_Point
{
public:
	HasPtr_Point(const string& s = string()):ps(new string(s)), i(0), use(new size_t(1)){}

	HasPtr_Point(const HasPtr_Point& p) :ps(p.ps), i(p.i), use(p.use) { ++(* use); }
	HasPtr_Point& operator=(const HasPtr_Point& );
	~HasPtr_Point();

private:
	string *ps;
	int i;
	size_t *use;
};

