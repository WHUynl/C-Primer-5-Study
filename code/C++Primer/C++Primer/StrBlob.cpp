#include"StrBlob.h"
#include<stdexcept>
using namespace std;
StrBlob::StrBlob():data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string& msg) const {
	if (i >= data->size()) {
		throw out_of_range(msg);
	}
}
string& StrBlob::front() {
	check(0, "front empty");
	return data->front();
}

string& StrBlob::back() {
	check(0, "back empty");
	return data->back();
}

void StrBlob::pop_back() {
	check(0, "pop empty");
	data->pop_back();
}