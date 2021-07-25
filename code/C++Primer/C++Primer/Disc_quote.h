#pragma once
#include "Quote.h"
#include<utility>
class Disc_quote :
    public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price, size_t qty=10, double disc=10.0) :
        Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(size_t) const = 0;//纯虚函数
    pair<size_t, double> discount_policy() const { return { quantity,discount }; }
    Disc_quote(const Disc_quote& d):Quote(d) { cout << "Disc_quote的拷贝构造函数" << endl; }
    Disc_quote(Disc_quote&& d):Quote(d) { cout << "Disc_quote的移动构造函数" << endl; }
    virtual ~Disc_quote() { cout << "Disc_quote的析构函数" << endl; }

protected:
    size_t quantity = 0;//折扣适用的购买量
    double discount = 0.0;//表示折扣的小数值
};

