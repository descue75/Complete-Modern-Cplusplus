#include <iostream>
#include <limits>
#include <string>

int main() {
    std::cout << "Output\n" << 45 << " " << 8.2f << std::endl;

    int age;
    std::cout << "Tell me your age: ";
    std::cin >> age;
    std::cout << "Your age is: " << age << std::endl;

    std::string first_name;
    std::cout << "What is your first name? ";
    std::cin >> first_name;
    std::cout << "Your first name is: " << first_name << std::endl;

    std::string full_name;
    std::cout << "What is your full name? ";
    // Ignore everything currently left in the input buffer
    // up to and including the first newline.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Read the entire next line, including spaces,
    // stopping before the newline.
    std::getline(std::cin, full_name);

    std::cout << "Your full name is: " << full_name << std::endl;

    return 0;
}