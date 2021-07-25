#pragma once
#include<iostream>
using namespace std;
typedef char C;
template<typename C> C f5(C a);


template <typename T> class Screen 
{
public:
	Screen(T wid, T hei) :width(wid), height(hei) {};
	~Screen ();
	//注意友元函数与模板类均为多对多
	template <class U>
	friend istream& operator>>(istream& is, Screen<U>& s);
	template <class U>
	friend ostream& operator<<(ostream& os, Screen<U>& s);
private:
	T width;
	T height;
};
template <typename T>
Screen<T> ::~Screen ()
{
	cout << "我没了" << endl;
}

template <typename T>
istream& operator>>(istream& is, Screen<T>& s) {
	is >> s.width;
	is >> s.height;
	return is;
}

template <typename U>
ostream& operator<<(ostream& os, Screen<U>& s) {
	os << "屏幕的高度是: " << s.height << " 屏幕的宽度是: " << s.width;
	return os;
}

