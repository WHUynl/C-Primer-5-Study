#include"HasPtr_Point.h"

HasPtr_Point& HasPtr_Point:: operator=(const HasPtr_Point& p) {
	//�Ҳ�����ü�1
	++*p.use;
	//�������û�������ˣ�������Ҫɾ������������Դ
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