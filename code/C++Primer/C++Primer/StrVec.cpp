//#include"StrVec.h"
//
//void StrVec::push_back(const string& s) {
//	chk_n_alloc();//确保有空间容纳新元素
//	//在first_free指向的元素中构造s的副本
//	alloc.construct(first_free++, s);
//}
//
//pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) {
//	//分配空间保存给定范围的元素
//	auto data = alloc.allocate(e - b);
//	//初始化一个pair,由data和uninitialized_copy的返回值构成
//	return { data,uninitialized_copy(b,e,data) };
//}
//
//void StrVec::free() {
//	//不能传递空指针
//	if (elements) {
//		for (auto p = first_free; p != elements;/*空*/)
//			alloc.destroy(--p);
//		alloc.deallocate(elements, cap - elements);
//	}
//}
//
//StrVec::StrVec(const StrVec& s) {
//	auto newdata = alloc_n_copy(s.begin(), s.end());//该pair包含了首尾指针
//	elements = newdata.first;
//	first_free = cap = newdata.second;
//}
//
//StrVec& StrVec::operator=(const StrVec& s) {
//	auto data = alloc_n_copy(s.begin(), s.end());
//	free();
//	elements = data.first;
//	first_free = cap = data.second;
//	return *this;
//}
//
//StrVec& StrVec::operator=(StrVec&& rhs) noexcept {
//	//直接检测自赋值
//	if (this != &rhs) {
//		free();
//		elements = rhs.elements;//接管资源
//		first_free = rhs.first_free;
//		cap = rhs.cap;
//		rhs.elements = rhs.first_free = rhs.cap = nullptr;
//	}
//	return *this;
//}
//
//void StrVec::reallocate() {
//	//我们将分配当前大小两倍的内存空间
//	auto newcapacity = size() ? 2 * size() : 1;
//	//分配新内存
//	auto newdata = alloc.allocate(newcapacity);
//	//将数据从就内存移动到新内存
//	auto dest = newdata; //指向新数组的下一个元素
//	auto elem = elements;//指向旧数组的下一个元素
//	for (size_t i = 0; i != size(); ++i) {
//		alloc.construct(dest++, std::move(*elem++));
//	}
//	free();//一旦移动完元素就释放旧内存空间
//	//更新数据结构，执行新元素
//	elements = newdata;
//	first_free = dest;
//	cap = elements + newcapacity;
//}