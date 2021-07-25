#include "Basket.h"

double print_total(ostream& os, const Quote& item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << "# sold: " << n << " total due: " << ret << endl;
	return ret;
}

double Basket::total_receipt(ostream& os) const {
	double sum = 0.0;//保存实时总价格
	//iter指向ISBN相同的一批元素的第一个
	//upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
	for (auto iter = items.cbegin();
		iter != items.cend();
		iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}