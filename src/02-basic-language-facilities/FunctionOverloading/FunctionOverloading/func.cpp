#include <iostream>

extern "C" void Print(int* x) {
	std::cout << *x << '\n';
}