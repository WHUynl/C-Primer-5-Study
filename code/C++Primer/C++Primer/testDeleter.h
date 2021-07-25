#pragma once
#include<iostream>
#include<memory>
using namespace std;
struct  testDeleter
{
	int k = 0;
	testDeleter(int i):k(i){}

};

void end(testDeleter* t) {
	std::cout << t->k << " delete test" << std::endl;
}
