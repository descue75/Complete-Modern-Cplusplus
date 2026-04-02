#include <iostream>
#include <vector>

int main() {
	const size_t rows = 2;
	const size_t cols = 3;

	std::vector<std::vector<int>> data(rows, std::vector<int>(cols));

	// fill values
	for (size_t r = 0; r < rows; ++r) {
		for (size_t c = 0; c < cols; ++c) {
			data[r][c] = static_cast<int>(r * cols + c + 1);
		}
	}

	// print values
	for (const auto& row : data) {
		for (const auto& val : row) {
			std::cout << val << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}