#include <iostream>
#include <new>

int main() {
	const size_t rows = 2;
	const size_t cols = 3;

	int* data = nullptr;

	try {
		data = new int[rows * cols];
	}
	catch (const std::bad_alloc&) {
		std::cerr << "allocation failed\n";
		return 1;
	}

	// fill values
	for (size_t r = 0; r < rows; ++r) {
		for (size_t c = 0; c < cols; ++c) {
			data[r * cols + c] = static_cast<int>(r * cols + c + 1);
		}
	}

	// print values
	for (size_t r = 0; r < rows; ++r) {
		for (size_t c = 0; c < cols; ++c) {
			std::cout << data[r * cols + c] << ' ';
		}
		std::cout << '\n';
	}

	delete[] data;
	data = nullptr;

	return 0;
}