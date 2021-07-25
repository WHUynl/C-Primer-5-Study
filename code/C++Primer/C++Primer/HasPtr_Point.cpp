#include"HasPtr_Point.h"

HasPtr_Point& HasPtr_Point:: operator=(const HasPtr_Point& p) {
	//右侧的引用加1
	++*p.use;
	//左侧的如果没有引用了，我们需要删除左侧的所有资源
	if (-- * use == 0) {
		delete ps;
		delete use;
	}
	ps = p.ps;
	i = p.i;
	use = p.use;
	return *this;
}

HasPtr_Point::~HasPtr_Point() {
	if (--*use==0){
		delete ps;
		delete use;
	}
}