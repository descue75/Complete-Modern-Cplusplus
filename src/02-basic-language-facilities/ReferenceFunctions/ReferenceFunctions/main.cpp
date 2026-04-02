#include <iostream>

/*
Assignment
Implement the following functions

void Add(int a, int b, int& result);    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int& result);    //Find factorial of a number and return that through a reference parameter
void Swap(int& a, int& b);            //Swap two numbers through reference arguments
*/

void Add(int a, int b, int& result)
{
	result = a + b;
}

void Swap(int& a, int& b)
{
	// note: this is simpler than the pointer version because no dereferencing is needed
	int temp = a;
	a = b;
	b = temp;
}

void Factorial(int a, int& result)
{
	if (a < 0)
	{
		result = 0; // invalid input
		return;
	}

	result = 1;
	for (int i = 2; i <= a; ++i)
	{
		result *= i;
	}
}

int main()
{
	int x = 5;
	int y = 10;
	int result = 0;

	Add(x, y, result);
	std::cout << result << '\n';

	std::cout << x << ", " << y << '\n';
	Swap(x, y);
	std::cout << x << ", " << y << '\n';

	Factorial(x, result);
	std::cout << result << '\n';

	return 0;
}