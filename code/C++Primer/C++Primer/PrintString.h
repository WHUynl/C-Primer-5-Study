#pragma once
#include<iostream>
#include<ostream>
#include<string>
using namespace std;

class PrintString {
public:
	PrintString(ostream& o = cout, char c = ' ') :os(o), sep(c) {}
	void operator()(const string& s) const { os << s << sep; }
	string operator()(istream& i) { string s = ""; if (i >> s) { return s; }return s; }
private:
	ostream& os;//用于写入目的流
	char sep;//用于将不同输出隔开的字符
};