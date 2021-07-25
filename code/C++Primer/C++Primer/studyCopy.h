#pragma once
#include<iostream>
using namespace std;
class studyCopy
{
public:
	studyCopy(int num) :k(num) { cout << "正常的构造函数" << endl; }
	studyCopy(const studyCopy& s) :k(s.k) { cout << "调用拷贝构造函数" << endl; }
	studyCopy& operator=(const studyCopy& s) { k = s.k; cout << "调用合成运算符" << endl; return *this; }
	~studyCopy() { cout << "调用析构函数" << endl; }
	int k = 0;
};

 