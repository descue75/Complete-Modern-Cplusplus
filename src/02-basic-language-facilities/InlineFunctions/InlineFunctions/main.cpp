#include <iostream>

#define SquareMacro(x) x*x

// corrected macro (use parentheses to avoid precedence issues)
//#define SquareMacro(x) ((x) * (x))

inline int Square(int x) {
	return x * x;
}

int main() {
	int val = SquareMacro(5);
	std::cout << val << '\n';

	// bug: expands to 5 + (1 * 5) + 1 = 11
	val = SquareMacro(5 + 1);
	std::cout << val << '\n';

	val = Square(5);
	std::cout << val << '\n';

	// now correct
	val = Square(5 + 1);
	std::cout << val << '\n';

	return 0;
}