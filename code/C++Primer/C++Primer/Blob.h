#pragma once
#include <vector>
#include <memory>
#include <string>
using namespace std;

/*
template<typename T> class Blob
{
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	//构造函数
	Blob();
	Blob(std::initializer_list<T> li);
	//Blob中的元素数目
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	//添加和删除元素
	void push_back(const T& t) { data->push_back(t); }
	//移动版本
	//void push_back(T&& t) { data->push_back(std::move(t); }
	void pop_back();
	T& back();
	T& operator[](size_type i);
private:
	shared_ptr<vector<T>> data;
	//若data[i]无效，则抛出msg
	void check(size_type i, const string& msg) const;
};



template <typename T>
Blob<T>::Blob() :
	data(std::make_shared<std::vector<T>>()) { }

#ifdef INITIALIZER_LIST  
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T>>(il)) { }
#endif

// check member
template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}



template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T> void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}





template <typename T>
T& Blob<T>::operator[](size_type i)
{
	// if i is too big, check will throw, preventing access to a nonexistent element
	check(i, "subscript out of range");
	return (*data)[i];
}



// operators
template <typename T>
std::ostream&
operator<<(std::ostream& os, const Blob<T> a)
{
	os << "< ";
	for (size_t i = 0; i < a.size(); ++i)
		os << a[i] << " ";
	os << " >";
	return os;
}

template <typename T>
bool
operator==(const Blob<T> lhs, const Blob<T> rhs)
{
	if (rhs.size() != lhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); ++i) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

// BlobPtr throws an exception on attempts to access a nonexistent element 
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr : public std::iterator<std::bidirectional_iterator_tag, T> {
	friend bool
		operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
	BlobPtr() : curr(0) { }
	BlobPtr(Blob<T>& a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }

	T& operator[](std::size_t i)
	{
		auto p = check(i, "subscript out of range");
		return (*p)[i];  // (*p) is the vector to which this object points
	}

	const T& operator[](std::size_t i) const
	{
		auto p = check(i, "subscript out of range");
		return (*p)[i];  // (*p) is the vector to which this object points
	}

	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];  // (*p) is the vector to which this object points
	}
	T* operator->() const
	{ // delegate the real work to the dereference operator
		return &this->operator*();
	}

	// increment and decrement
	BlobPtr& operator++();       // prefix operators
	BlobPtr& operator--();

	BlobPtr operator++(int);     // postfix operators
	BlobPtr operator--(int);

private:
	// check returns a shared_ptr to the vector if the check succeeds
	std::shared_ptr<std::vector<T>>
		check(std::size_t, const std::string&) const;

	// store a weak_ptr, which means the underlying vector might be destroyed
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;      // current position within the array
};

// equality operators
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.wptr.lock().get() == rhs.wptr.lock().get() &&
		lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(lhs == rhs);
}

// check member
template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();   // is the vector still around?
	if (!ret)
		throw std::runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret; // otherwise, return a shared_ptr to the vector
}

// member operators
// postfix: increment/decrement the object but return the unchanged value
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	// no check needed here; the call to prefix increment will do the check
	BlobPtr ret = *this;   // save the current value
	++* this;     // advance one element; prefix ++ checks the increment
	return ret;  // return the saved state
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	// no check needed here; the call to prefix decrement will do the check
	BlobPtr ret = *this;  // save the current value
	--* this;     // move backward one element; prefix -- checks the decrement
	return ret;  // return the saved state
}

// prefix: return a reference to the incremented/decremented object
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	// if curr already points past the end of the container, can't increment it
	check(curr, "increment past end of BlobPtr");
	++curr;       // advance the current state
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	// if curr is zero, decrementing it will yield an invalid subscript
	--curr;       // move the current state back one element
	check(-1, "decrement past begin of BlobPtr");
	return *this;
}
*/