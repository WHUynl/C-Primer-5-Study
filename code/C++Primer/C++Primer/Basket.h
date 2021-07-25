#pragma once
#include<memory>
#include"Bulk_quote.h"
#include<set>
using namespace std;
class Basket
{
public:
	//Basket使用合成默认构造函数和拷贝函数
	void add_item(const shared_ptr<Quote>& sale) { items.insert(sale); }
	//打印每本书的总价和购物篮中所有书的总价
	double total_receipt(ostream&) const;
	void add_item(const Quote& sale) { items.insert(shared_ptr<Quote>(sale.clone())); }
	void add_item(Quote&& sale) { items.insert(shared_ptr<Quote>(std::move(sale).clone())); }
	
private:
	//用于比较shared_ptr，multiset成员会进行使用
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) { return lhs->isbn() < rhs->isbn(); }
	//multiset保存多个报价，按照compare成员排序
	multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

