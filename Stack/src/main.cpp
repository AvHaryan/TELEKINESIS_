#include <iostream>
#include "stack.hpp"

int main() {
    stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    std::cout << intStack.size() << std::endl;
    std::cout << intStack.top() << std::endl;
    intStack.pop();
    std::cout << intStack.size() << std::endl;
}

