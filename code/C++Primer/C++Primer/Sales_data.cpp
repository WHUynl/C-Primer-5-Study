#include"Sales_data.h"
Sales_data::Sales_data(const Sales_data& orig) :bookNo(orig.bookNo),units_sold(orig.units_sold),revenue(orig.revenue){

}

Sales_data& Sales_data::operator+=(const Sales_data& s) {
	units_sold += s.units_sold;
	revenue += s.revenue;
	return *this;
}

Sales_data:: operator string() const {
	return this->bookNo;
}