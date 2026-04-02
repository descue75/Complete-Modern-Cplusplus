#include <iostream>
#include <new>

int main() {
	int data[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	std::cout << data[0][1] << '\n';

	int* p1 = nullptr;
	int* p2 = nullptr;
	int** pData = nullptr;

	try {
		p1 = new int[3] {1, 2, 3};
		p2 = new int[3] {4, 5, 6};

		pData = new int* [2];
		pData[0] = p1;
		pData[1] = p2;
	}
	catch (const std::bad_alloc&) {
		delete[] p1;
		delete[] p2;
		delete[] pData;
		return 1;
	}

	std::cout << pData[0][1] << '\n';

	delete[] p1;
	delete[] p2;
	delete[] pData;

	return 0;
}