#include <iostream>
#include <string>

void reverseString(std::string& str) {
    size_t start = 0;
    size_t end = str.length() - 1;

    while (start < end) {
        std::swap(str[start], str[end]);
        ++start;
        --end;
    }
}

int main() {
    std::string input = "Hello, World!";
    std::cout << "Original String: " << input << std::endl;

    reverseString(input);

    std::cout << "Reversed String: " << input << std::endl;

    return 0;
}
