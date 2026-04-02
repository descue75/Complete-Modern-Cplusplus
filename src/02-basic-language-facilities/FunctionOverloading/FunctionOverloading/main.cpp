#include <iostream>
#include "func.h"

int Add(int a, int b) {
	return a + b;
}

float Add(float a, float b) {
	return a + b;
}

int main() {
	int i = Add(3, 5);
	std::cout << i << '\n';
	float f = Add(3.1f, 5.2f);
	std::cout << f << '\n';

	Print(&i);
	return 0;
}