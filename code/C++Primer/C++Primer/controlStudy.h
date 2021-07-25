#pragma once
class Base {
public:
	void pub_mem();

protected:
	int prot_mem;

private:
	char priv_mem;

};

struct Pub_Derv:public Base
{
	int f() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }//公有继承没问题
};

struct Priv_Derv:private Base
{
	int f1() const { return prot_mem; }
	void memfcn(Base& b) { b = *this; }//成员函数也可以
};

struct Prot_Derv:protected Base
{
	void memfcn(Base& b) { b = *this; }
};

struct Derived_from_Public:public Pub_Derv
{
	void memfcn(Base& b) { b = *this; }
};

struct  Derived_from_Privated:public Priv_Derv
{
	
};

struct Derived_from_Protected:private Prot_Derv
{
	void memfcn(Base& b) { b = *this; }
};




/*
P546 练习第一题

对，错,错，对,错，错  只有public才能使用 使用 Base *p = new Derived();

第二题






*/