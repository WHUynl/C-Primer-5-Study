#include"HasPtr.h"
HasPtr& HasPtr::operator=(const HasPtr& h) {
	i = h.i;
	auto newp = new string(*(h.p));
	delete p;//ע��Ҫ�ͷ���ǰ����Դ
	p = newp;
	return *this;
}