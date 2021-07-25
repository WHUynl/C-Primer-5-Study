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
    double net_price(size_t) const = 0;//���麯��
    pair<size_t, double> discount_policy() const { return { quantity,discount }; }
    Disc_quote(const Disc_quote& d):Quote(d) { cout << "Disc_quote�Ŀ������캯��" << endl; }
    Disc_quote(Disc_quote&& d):Quote(d) { cout << "Disc_quote���ƶ����캯��" << endl; }
    virtual ~Disc_quote() { cout << "Disc_quote����������" << endl; }

protected:
    size_t quantity = 0;//�ۿ����õĹ�����
    double discount = 0.0;//��ʾ�ۿ۵�С��ֵ
};

