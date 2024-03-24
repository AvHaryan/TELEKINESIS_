#ifndef STACK_H
#define STACK_H

#include <vector>
#include <initializer_list>

template <typename T, typename Container = std::vector<T>>
class stack {
private:
    Container ob;

public: 
    stack() = default;
    stack(const stack& other) = default;
    stack(stack&& other) = default;
    stack(std::initializer_list<T> init) : ob{init} {}
    ~stack() = default;

    void push(const T& elem);
    void pop();
    T& top();
    size_t size() const;
    void swap(stack& other);
    bool empty() const;
};  
#include "stack.hpp"
#endif // STACK_H

