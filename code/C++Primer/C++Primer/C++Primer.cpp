// C++Primer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include<deque>
#include<list>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include"testDeleter.h"
#include"HasPtr.h"
#include"PrintString.h"
#include"studyCopy.h"
#include"CheckStringLength.h"
#include<functional>
#include"Bulk_quote.h"
#include"List.h"
#include"Screen.h"
using namespace std;


bool test(const vector<int>& v, int val) {
	auto be = v.begin();
	auto en = v.end();
	while (be != en) {
		if (val == *be) {
			
			return true;
		}
		++be;
	}
	return false;
}

string replaceString(string s, string oldVal, string newVal) {
	int len = s.size();
	int len2 = oldVal.size();
	int len3 = newVal.size();
	int pos = 0;
	while (pos + len2 <= len) {
		if (s.substr(pos, len2) == oldVal) {
			s.replace(pos, len2, newVal);
			pos += len3;
			len = s.size();
		}
		else{
			pos++;
		}
	}
	return s;

}

int testCount(const list<int>l, int val) {
	int num = count(l.begin(), l.end(), val);
	return num;
}

bool check_size(const string& s, int num) {
	return s.size() < num;
}

void outPut(const int a,ostream_iterator<int> &b,ostream_iterator<int> &c) {
	if (a % 2) {
		b = a;
	}
	else {
		c = a;
	}
}


struct MyStruct
{
	int test;
	MyStruct(int i) :test(i) {}
};

bool compareMy(const MyStruct& l, const MyStruct& r) {
	return l.test < r.test;
}

vector<int> *makeVector() {
	return new vector<int>{ 1,2,3 };
}
 
vector<int>* cinVector(vector<int> *v) {
	int i;
	while (cin >> i) {
		v->push_back(i);
	}
	return v;
}

void printVector(vector<int> *v) {
	for (auto a : *v) {
		cout << a << " ";
	}
	delete v;
}

void printVector2(shared_ptr<vector<int>> v) {
	for (auto a : *v) {
		cout << a << " ";
	}
}
shared_ptr<vector<int>> makeVector2() {
	return make_shared < vector<int>>();
}

shared_ptr<vector<int>> cinVector2(shared_ptr<vector<int>> v) {
	int i;
	while (cin >> i) {
		v->push_back(i);
	}
	return v;
}

studyCopy testStuCopy(studyCopy s) {
	cout << "hello" << endl;
	return s;
}

bool func(const studyCopy* trans, studyCopy accum) {
	studyCopy item1(*trans), item2(accum);
	return item1.k != item2.k;
}

int f(int i) {
	return 1;
}

template <class T> int Hcompare( T*) {
	//cout << T<<endl;
	return 1;
}


template <typename T>
ostream& print(ostream& os, const T& t) {
	return os << t << endl;
}

template <typename T,typename ...Args>
ostream& print(ostream& os, const T& t,const Args&... rest) {
	os << t << endl;
	return print(os, rest...+);
}
int main(){
	int i = 0;
	string s = string("test");
	print(cout, i, s, 42);

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
