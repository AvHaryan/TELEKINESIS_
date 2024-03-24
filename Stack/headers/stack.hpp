#ifndef STACK_HPP
#define STACK_HPP
#include "stack.h"

template <typename T, typename Container>
void 
   stack<T, Container>::push(const T& elem) {
       ob.push_back(elem);
   }

template <typename T, typename Container>
void 
   stack<T, Container>::pop() {
       if (!ob.empty()) {
           ob.pop_back();
       }
   }

template <typename T, typename Container>
T&
   stack<T, Container>::top() {
     return  ob.back();
   }

template <typename T, typename Container>
size_t
   stack<T, Container>::size() const {
       return ob.size();
   }

template <typename T, typename Container>
void 
   stack<T, Container>::swap(stack& other) {
       std::swap(ob, other.ob);
   }

template <typename T, typename Container>
bool
   stack<T, Container>::empty() const {
       return ob.empty();
   }


#endif //STACK_HPP
