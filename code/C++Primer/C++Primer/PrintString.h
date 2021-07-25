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
	ostream& os;//����д��Ŀ����
	char sep;//���ڽ���ͬ����������ַ�
};