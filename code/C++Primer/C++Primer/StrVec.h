#pragma once
#include<memory>
#include<string>
#include<utility>
using namespace std;
class StrVec
{
public:
	StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);//拷贝元素
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }

	//移动构造函数
	StrVec(StrVec&& s) noexcept :elements(s.elements), first_free(s.first_free), cap(s.cap) { s.elements = s.first_free = s.cap = nullptr; }
	StrVec& operator=(StrVec&&) noexcept;

private:
	static allocator<string> alloc;//分配元素
	//被添加元素的函数所使用
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	//工具函数，被拷贝构造函数，赋值运算符，析构函数所用。
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();//销毁元素并释放内存
	void reallocate();//获得更多内存并拷贝已有的元素
	string* elements;//指向数组首元素指针
	string* first_free;//指向数组第一个空闲元素的指针
	string* cap;//指向数组尾后的位置的指针
};

