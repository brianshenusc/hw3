#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    // two data members, one for the current top index and one that is the stack with its size
    int top_index;
    T stack[100];
};
// Sets the current top index to -1 (since nothing is in the stack initially)
template <typename T>
Stack<T>::Stack() {
    top_index = -1;
}
// default destructor
template <typename T>
Stack<T>::~Stack() {

}
// If the stack is empty (top_index is -1) then returns true, false otherwise 
template <typename T>
bool Stack<T>::empty() const {
    if(top_index == -1) {
        return true;
    }
    return false;
}
// returns the size of the stack
template <typename T>
size_t Stack<T>::size() const {
    return top_index + 1;
}
// adds to end of stack
template <typename T>
void Stack<T>::push(const T& item) {
    top_index++;
    stack[top_index] = item;
}

// throws std::underflow_error if empty, otherwise deletes an item
template <typename T>
void Stack<T>::pop() {
    if(empty()) {
        throw std::underflow_error("The stack is empty");
    }
    else {
        top_index--;
    }
}  

// throws std::underflow_error if empty, else returns top item
template <typename T>
const T& Stack<T>::top() const {
    if(empty()) {
        throw std::underflow_error("The stack is empty");
    }
    else {
        return stack[top_index];
    } 
}


#endif