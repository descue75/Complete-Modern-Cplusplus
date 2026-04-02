#include <iostream>

/*
Assignment
Implement the following functions using pointer arguments only

int Add(int* a, int* b);    //Add two numbers and return the sum
void AddVal(int* a, int* b, int* result); //Add two numbers and return the sum through the third pointer argument
void Swap(int* a, int* b);  //Swap the value of two integers
void Factorial(int* a, int* result);       //Generate the factorial of a number and return that through the second pointer argument
*/

int Add(int* a, int* b)
{
	return *a + *b;
}

void AddVal(int* a, int* b, int* result)
{
	*result = *a + *b;
}

void Swap(int* a, int* b)
{
	// wrong: a and b are copies of the pointers, so swapping them does not affect the caller
	//int* temp = a;
	//a = b;
	//b = temp;

	int temp = *a;
	*a = *b;
	*b = temp;
}

void Factorial(int* a, int* result)
{
	if (*a < 0)
	{
		*result = 0; // invalid input
		return;
	}

	*result = 1;
	for (int i = 2; i <= *a; ++i)
	{
		*result *= i;
	}
}

int main() {
	int x = 5;
	int y = 10;
	int z = 0;

	int result = Add(&x, &y);
	std::cout << result << std::endl;

	AddVal(&x, &y, &z);
	std::cout << z << std::endl;

	std::cout << x << ", " << y << std::endl;
	Swap(&x, &y);
	std::cout << x << ", " << y << std::endl;

	Factorial(&x, &result);
	std::cout << result;

	return 0;
}