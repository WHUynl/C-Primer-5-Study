#include"HasPtr.h"
HasPtr& HasPtr::operator=(const HasPtr& h) {
	i = h.i;
	auto newp = new string(*(h.p));
	delete p;//注意要释放以前的资源
	p = newp;
	return *this;
}