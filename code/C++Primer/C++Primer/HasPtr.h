#pragma once
#include<string>
#include<iostream>
using namespace std;
class HasPtr
{
public:
	HasPtr() :i(0), p(new string("")) {}
	HasPtr(const HasPtr& h) :i(h.i), p(new string(*(h.p))) { cout<<"����"<<endl; }
	HasPtr& operator=(const HasPtr& h);
	HasPtr& operator=(HasPtr rhs) {
		swap(*this, rhs); return *this;
	}
	HasPtr( HasPtr&& p) noexcept :p(p.p), i(p.i) { p.p = 0; cout << "�ƶ�"<<endl; }//��ָ���ͷ�
	~HasPtr() { delete p; }
private:
	string* p;
	int i;
	friend void swap(HasPtr &l, HasPtr& r);
};

inline void swap(HasPtr& l, HasPtr& r) {
	swap(l.p, r.p);
	swap(l.i, r.i);
	cout << "swap������" << endl;
}
