#pragma once
#include<string>
#include<iostream>
using namespace std;
class HasPtr
{
public:
	HasPtr() :i(0), p(new string("")) {}
	HasPtr(const HasPtr& h) :i(h.i), p(new string(*(h.p))) { cout<<"拷贝"<<endl; }
	HasPtr& operator=(const HasPtr& h);
	HasPtr& operator=(HasPtr rhs) {
		swap(*this, rhs); return *this;
	}
	HasPtr( HasPtr&& p) noexcept :p(p.p), i(p.i) { p.p = 0; cout << "移动"<<endl; }//将指针释放
	~HasPtr() { delete p; }
private:
	string* p;
	int i;
	friend void swap(HasPtr &l, HasPtr& r);
};

inline void swap(HasPtr& l, HasPtr& r) {
	swap(l.p, r.p);
	swap(l.i, r.i);
	cout << "swap结束了" << endl;
}
