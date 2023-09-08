#include <iostream>
#include "uniqueptr.h"

class A {
public:
	int a = 0;
	A(int b) : a(b){}
};

class Deleter {
public:
	template<typename T>
	void operator()(T* ptr) {
		std::cout << "del" << std::endl;
		ptr = nullptr;
		delete ptr;
	}
};

class arr_Deleter {
public:
	template<typename T>
	void operator()(T* ptr) {
		std::cout << "arr_del" << std::endl;
		ptr = nullptr;
		delete[] ptr;
	}
};

int main() {
	uniqueptr<int, Deleter> ptr{new int(120)};
	uniqueptr<A, Deleter> ptr2{new A(5)};
	uniqueptr<int[],arr_Deleter> ptr3{new int[4]};

	std::cout << *ptr << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ptr2->a << std::endl;
	std::cout << *ptr3 << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << ptr3[i] << std::endl;
	}
}