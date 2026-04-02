#include <iostream>

void PrintPtr(const int* ptr) {
	std::cout << *ptr << std::endl;

	// not allowed
	// *ptr = 700;
}

void PrintRef(int& ref) {
	std::cout << ref << std::endl;

	// allowed
	ref = 10;
}

void PrintConstRef(const int& ref) {
	std::cout << ref << std::endl;

	// not allowed
	// ref = 10;
}

void Assignment() {
	/*
	Write the following code & do as instructed in the comments. Build and observe.
	*/

	// Try to modify x1 & x2 and see the compilation output
	int x = 5;
	const int MAX = 12;
	int& ref_x1 = x;
	const int& ref_x2 = x;

	ref_x1 = MAX;
	// not allowed
	// ref_x2 = MAX;

	// Try to modify the pointer and/or the pointee value
	const int* ptr1 = &x;        // pointer to const int
	int* const ptr2 = &x;        // const pointer to int
	const int* const ptr3 = &x;  // const pointer to const int

	int i = 10;

	ptr1 = &i;   // allowed: pointer can be reseated
	// *ptr1 = 11; // not allowed: pointee is const

	// ptr2 = &i; // not allowed: pointer is const
	*ptr2 = 11;  // allowed: pointee is non-const

	// ptr3 = &i; // not allowed: pointer is const
	// *ptr3 = 11; // not allowed: pointee is const

	// Find which declarations are valid. If invalid, correct the declaration
	const int* ptr4 = &MAX;
	// int* ptr5 = &MAX; // invalid
	const int* ptr5 = &MAX;

	const int& r1 = ref_x1;
	// int& r2 = ref_x2; // invalid
	const int& r2 = ref_x2;

	// int*& p_ref1 = ptr1; // invalid
	const int*& p_ref1 = ptr1;

	// const int*& p_ref2 = ptr2; // invalid
	int* const& p_ref2 = ptr2;
}

int main() {
	const int CHUNK_SIZE = 512;

	// not allowed
	// int* ptr = &CHUNK_SIZE;

	const int* ptr = &CHUNK_SIZE;

	// not allowed
	// *ptr = 1;

	int x = 10;
	ptr = &x;

	// still not allowed
	// *ptr = 1;

	const int* const constPtr = &CHUNK_SIZE;

	// not allowed to change value OR address
	// constPtr = &x;
	// *constPtr = 1;

	PrintPtr(&x);
	std::cout << "main->x " << x << std::endl;

	// not allowed
	// PrintRef(5);

	const int& ref = 5;
	PrintConstRef(5);
	PrintConstRef(ref);

	Assignment();

	return 0;
}