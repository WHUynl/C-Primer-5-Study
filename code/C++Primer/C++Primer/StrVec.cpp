//#include"StrVec.h"
//
//void StrVec::push_back(const string& s) {
//	chk_n_alloc();//ȷ���пռ�������Ԫ��
//	//��first_freeָ���Ԫ���й���s�ĸ���
//	alloc.construct(first_free++, s);
//}
//
//pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) {
//	//����ռ䱣�������Χ��Ԫ��
//	auto data = alloc.allocate(e - b);
//	//��ʼ��һ��pair,��data��uninitialized_copy�ķ���ֵ����
//	return { data,uninitialized_copy(b,e,data) };
//}
//
//void StrVec::free() {
//	//���ܴ��ݿ�ָ��
//	if (elements) {
//		for (auto p = first_free; p != elements;/*��*/)
//			alloc.destroy(--p);
//		alloc.deallocate(elements, cap - elements);
//	}
//}
//
//StrVec::StrVec(const StrVec& s) {
//	auto newdata = alloc_n_copy(s.begin(), s.end());//��pair��������βָ��
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
//	//ֱ�Ӽ���Ը�ֵ
//	if (this != &rhs) {
//		free();
//		elements = rhs.elements;//�ӹ���Դ
//		first_free = rhs.first_free;
//		cap = rhs.cap;
//		rhs.elements = rhs.first_free = rhs.cap = nullptr;
//	}
//	return *this;
//}
//
//void StrVec::reallocate() {
//	//���ǽ����䵱ǰ��С�������ڴ�ռ�
//	auto newcapacity = size() ? 2 * size() : 1;
//	//�������ڴ�
//	auto newdata = alloc.allocate(newcapacity);
//	//�����ݴӾ��ڴ��ƶ������ڴ�
//	auto dest = newdata; //ָ�����������һ��Ԫ��
//	auto elem = elements;//ָ����������һ��Ԫ��
//	for (size_t i = 0; i != size(); ++i) {
//		alloc.construct(dest++, std::move(*elem++));
//	}
//	free();//һ���ƶ���Ԫ�ؾ��ͷž��ڴ�ռ�
//	//�������ݽṹ��ִ����Ԫ��
//	elements = newdata;
//	first_free = dest;
//	cap = elements + newcapacity;
//}