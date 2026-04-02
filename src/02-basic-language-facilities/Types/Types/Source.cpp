# include <iostream>

int main() {
	// Scalar types
	int i = 0;
	// Uniform initialization (C++ 11)
	int i2{ 0 };
	std::cout << i;
	char ch = 'a';
	bool flag = false;

	float f = 1.123f;
	double d = 521.342;

	// Vector types
	int arr[5];

	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5]{ 1,2,3,4,5 };
}