#include <iostream>
#include <new>

void PrintArray(const int* arr, size_t count) {
	for (size_t i = 0; i < count; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

int main() {
	const size_t count = 5;

	int* p = nullptr;

	try {
		p = new int[count];
	}
	catch (const std::bad_alloc&) {
		std::cerr << "new failed\n";
		return 1;
	}

	// NOTE: reading uninitialized memory is undefined behavior (demo only)
	std::cout << "new[] (uninitialized): ";
	PrintArray(p, count);

	p[0] = 6;
	p[1] = 11;

	std::cout << "new[] (after assignment): ";
	PrintArray(p, count);

	delete[] p;
	p = nullptr;

	try {
		p = new int[count]();
	}
	catch (const std::bad_alloc&) {
		std::cerr << "new[] value-initialization failed\n";
		return 1;
	}

	std::cout << "new[]() (value-initialized): ";
	PrintArray(p, count);

	p[0] = 6;
	p[1] = 11;

	std::cout << "new[]() (after assignment): ";
	PrintArray(p, count);

	delete[] p;
	p = nullptr;

	return 0;
}