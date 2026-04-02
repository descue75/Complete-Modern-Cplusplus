#include <iostream>

void Print(char ch, int count) {
	for (int i = 0; i < count; ++i) {
		std::cout << ch;
	}
	std::cout << '\n';
}

void EndMessage() {
	std::cout << "end of program\n";
}

int main() {
	atexit(EndMessage);

	Print('c', 5);

	void (*pfn)(char, int) = Print;
	(*pfn)('#', 8);
	pfn('#', 8);

	std::cout << "end of main\n";

	return 0;
}