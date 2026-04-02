#include <iostream>
#include <vector>

int main() {
	int x = 10;
	auto y = x;          // int

	const int cx = 20;
	auto z = cx;         // int (const dropped)

	auto& ref = cx;      // const int&

	std::vector<int> v = { 1, 2, 3 };

	for (auto i : v) {   // copy
		std::cout << i << ' ';
	}

	for (auto& i : v) {  // reference
		i *= 2;
	}

	// doesn't work
	//auto list{ 1, 2, 3 };
	auto list = { 1, 2, 3 }; // std::initializer_list<int> (C++ 11)

	return 0;
}