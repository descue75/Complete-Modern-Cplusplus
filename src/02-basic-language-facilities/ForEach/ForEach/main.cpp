#include <iostream>
#include <vector>

int main() {
	int arr[]{ 1, 2, 3 };

	// range-based for (array)
	for (const auto& x : arr) {
		std::cout << x << ' ';
	}
	std::cout << '\n';

	// pointer traversal (int*)
	for (auto ptr = std::begin(arr); ptr != std::end(arr); ++ptr) {
		std::cout << *ptr << ' ';
	}
	std::cout << '\n';

	std::vector<int> vec{ 1, 2, 3, 4 };

	// range-based for (vector)
	for (const auto& x : vec) {
		std::cout << x << ' ';
	}
	std::cout << '\n';

	// iterator traversal (std::vector<int>::iterator)
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << '\n';

	// range-based for (initializer_list<int>)
	for (const auto& x : { 1, 2, 3, 4, 5 }) {
		std::cout << x << ' ';
	}
	std::cout << '\n';

	return 0;
}