#pragma once
#include "Disc_quote.h"
class Bulk_quote :
    public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price, size_t qty, double disc) :
        Disc_quote(book, price, qty, disc),min_qty(qty),discount(disc) {}
    void debug() override;
    double net_price(size_t) const override;
    Bulk_quote(const Bulk_quote& b):Disc_quote(b){ cout << "Bulk_quoto�Ŀ������캯��" << endl; }
    Bulk_quote(Bulk_quote&& b) :Disc_quote(b) { cout << "Bulk_quoto���ƶ����캯��" << endl; }
    virtual ~Bulk_quote() { cout << "Bulk_quote����������" << endl; }
    Bulk_quote* clone()const& { return new Bulk_quote(*this); }
    Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); }
private:
    size_t min_qty = 0;
    double discount = 0.0;
protected:
    int test = 0;
};

