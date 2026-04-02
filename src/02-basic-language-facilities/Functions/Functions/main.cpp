#include <iostream>
#include "math.h"

void Print(char ch) {
	for (int i = 0; i < 10; ++i) {
		std::cout << ch;
	}
	std::cout << std::endl;
}

int main() {
	int x, y;
	std::cin >> x >> y;
	int result = Add(x, y);
	std::cout << result << std::endl;

	Print('#');
}
