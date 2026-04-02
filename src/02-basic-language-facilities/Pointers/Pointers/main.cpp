#include <iostream>

int main() {
	int x = 10;
	float y = 1.2f;

	std::cout << &x << '\n';
	int* ptr = &x;
	// prints the address stored in ptr
	std::cout << ptr << '\n';

	// compilation error - type mismatch
	// float* ptr = &x;

	// void* can store the address of any object type
	void* ptr2 = &x;
	ptr2 = &y;

	// dereference operator
	std::cout << *ptr << '\n';
	*ptr = 5;
	// modifies x through the pointer
	std::cout << ptr << '\n';
	std::cout << *ptr << '\n';
	int i = *ptr;
	std::cout << i << '\n';

	// null pointer (C++ 11)
	int* badptr;
	// uninitialized pointer (contains garbage) - do not use
	// std::cout << badptr << '\n';

	int* z = nullptr;
	std::cout << z << '\n';
	// runtime error - dereferencing null pointer
	// std::cout << *z << '\n';
	// *z = 10;
	return 0;
}