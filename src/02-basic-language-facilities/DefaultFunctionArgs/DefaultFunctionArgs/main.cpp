#include <iostream>

void CreateWindow(const char* title, int x = -1, int y = -1, int width = -1, int height = -1);

void CreateWindow(const char* title, int x, int y, int width, int height) {
	std::cout << "Title: " << title << '\n';
	std::cout << "X: " << x << '\n';
	std::cout << "Y: " << y << '\n';
	std::cout << "Width: " << width << '\n';
	std::cout << "Height: " << height << '\n';
}

int main() {
	CreateWindow("Notepad", 150, 200, 500, 600);
	std::cout << '\n';

	CreateWindow("Notepad");
	std::cout << '\n';

	CreateWindow("Notepad", 150, 200);

	return 0;
}