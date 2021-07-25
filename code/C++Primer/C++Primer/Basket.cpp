#include "Basket.h"

double print_total(ostream& os, const Quote& item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << endl;
	return ret;
}

double Basket::total_receipt(ostream& os) const {
	double sum = 0.0;//����ʵʱ�ܼ۸�
	//iterָ��ISBN��ͬ��һ��Ԫ�صĵ�һ��
	//upper_bound����һ�����������õ�����ָ������Ԫ�ص�β��λ��
	for (auto iter = items.cbegin();
		iter != items.cend();
		iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}