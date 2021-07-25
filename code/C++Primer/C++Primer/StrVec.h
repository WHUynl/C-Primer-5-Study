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
	void push_back(const string&);//����Ԫ��
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }

	//�ƶ����캯��
	StrVec(StrVec&& s) noexcept :elements(s.elements), first_free(s.first_free), cap(s.cap) { s.elements = s.first_free = s.cap = nullptr; }
	StrVec& operator=(StrVec&&) noexcept;

private:
	static allocator<string> alloc;//����Ԫ��
	//�����Ԫ�صĺ�����ʹ��
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	//���ߺ��������������캯������ֵ������������������á�
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();//����Ԫ�ز��ͷ��ڴ�
	void reallocate();//��ø����ڴ沢�������е�Ԫ��
	string* elements;//ָ��������Ԫ��ָ��
	string* first_free;//ָ�������һ������Ԫ�ص�ָ��
	string* cap;//ָ������β���λ�õ�ָ��
};

