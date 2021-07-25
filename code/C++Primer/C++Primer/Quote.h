#pragma once
#include<iostream>
#include<string>
using namespace std;
class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double sales_price) :bookNo(book), price(sales_price){}
	string isbn() const { return bookNo; }//返回编号
	virtual double net_price(size_t n) const { return n * price; }//返回实际价格
	virtual void debug();
	Quote(const Quote&) { cout << "Quote的拷贝构造函数" << endl; }
	Quote(Quote&&){ cout << "Quote的移动构造函数" << endl; }
	virtual ~Quote() { cout << "Quote的析构函数" << endl; }
	virtual Quote* clone()const & { return new Quote(*this); }
	virtual Quote* clone()&& { return new Quote(std::move(*this)); }
private:
	string bookNo;
protected:
	double price = 0.0;
};

