#include <iostream>
#include "uniqueptr.h"

class A {
public:
	int a = 0;
	A(int b) : a(b){}
};

int main() {
	uniqueptr<int> ptr{new int(120)};
	uniqueptr<A> ptr2{new A(5)};
	uniqueptr<int> ptr3{new int[4]};

	std::cout << *ptr << std::endl;
	std::cout << ptr2->a << std::endl;
	std::cout << *ptr3 << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << ptr3[i] << std::endl;
	}
}