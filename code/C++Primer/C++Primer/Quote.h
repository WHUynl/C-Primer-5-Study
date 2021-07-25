#pragma once
#include<iostream>
#include<string>
using namespace std;
class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double sales_price) :bookNo(book), price(sales_price){}
	string isbn() const { return bookNo; }//���ر��
	virtual double net_price(size_t n) const { return n * price; }//����ʵ�ʼ۸�
	virtual void debug();
	Quote(const Quote&) { cout << "Quote�Ŀ������캯��" << endl; }
	Quote(Quote&&){ cout << "Quote���ƶ����캯��" << endl; }
	virtual ~Quote() { cout << "Quote����������" << endl; }
	virtual Quote* clone()const & { return new Quote(*this); }
	virtual Quote* clone()&& { return new Quote(std::move(*this)); }
private:
	string bookNo;
protected:
	double price = 0.0;
};

