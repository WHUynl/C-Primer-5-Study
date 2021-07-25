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
	void memfcn(Base& b) { b = *this; }//���м̳�û����
};

struct Priv_Derv:private Base
{
	int f1() const { return prot_mem; }
	void memfcn(Base& b) { b = *this; }//��Ա����Ҳ����
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
P546 ��ϰ��һ��

�ԣ���,����,����  ֻ��public����ʹ�� ʹ�� Base *p = new Derived();

�ڶ���






*/