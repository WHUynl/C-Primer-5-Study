#pragma once
#include<iostream>
using namespace std;
class studyCopy
{
public:
	studyCopy(int num) :k(num) { cout << "�����Ĺ��캯��" << endl; }
	studyCopy(const studyCopy& s) :k(s.k) { cout << "���ÿ������캯��" << endl; }
	studyCopy& operator=(const studyCopy& s) { k = s.k; cout << "���úϳ������" << endl; return *this; }
	~studyCopy() { cout << "������������" << endl; }
	int k = 0;
};

 