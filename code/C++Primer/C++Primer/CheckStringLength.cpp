#include "CheckStringLength.h"
#include <algorithm>
#include <iostream>

using namespace std;
void CheckStringLength::operator()(fstream& fs,const string filename) {
	fs.open(filename);
	string tmp;
	while (fs >> tmp) {
		int length = tmp.length();
		if (length >= 10) {
			v[10]++;
		}
		else {
			v[length]++;
		}
	}
}

void CheckStringLength::outputAll() {
	for_each(v.begin(), v.end(), [](int i) { cout << i << endl; });
}