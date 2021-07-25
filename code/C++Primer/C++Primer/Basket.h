#pragma once
#include<memory>
#include"Bulk_quote.h"
#include<set>
using namespace std;
class Basket
{
public:
	//Basketʹ�úϳ�Ĭ�Ϲ��캯���Ϳ�������
	void add_item(const shared_ptr<Quote>& sale) { items.insert(sale); }
	//��ӡÿ������ܼۺ͹���������������ܼ�
	double total_receipt(ostream&) const;
	void add_item(const Quote& sale) { items.insert(shared_ptr<Quote>(sale.clone())); }
	void add_item(Quote&& sale) { items.insert(shared_ptr<Quote>(std::move(sale).clone())); }
	
private:
	//���ڱȽ�shared_ptr��multiset��Ա�����ʹ��
	static bool compare(const shared_ptr<Quote>& lhs, const shared_ptr<Quote>& rhs) { return lhs->isbn() < rhs->isbn(); }
	//multiset���������ۣ�����compare��Ա����
	multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

