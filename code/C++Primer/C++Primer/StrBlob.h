#pragma once
#include<vector>
#include<string>
#include<memory>
class StrBlob  
{
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> i1);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//���Ӻ�ɾ��Ԫ��
	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back();
	//Ԫ�ط���
	std::string& front();
	std::string& back();
private:
	std::shared_ptr<std::vector<std::string>> data;
	//���data[i]���Ϸ����׳�һ���쳣
	void check(size_type i, const std::string& msg) const;
};