#pragma once
#include<vector>
#include<fstream>
using namespace std;
class CheckStringLength
{
public:
	CheckStringLength() :v(vector<int>(11, 0)) {}
	void operator()(fstream&, const string);
	void outputAll();
private:
	vector<int> v;
};

