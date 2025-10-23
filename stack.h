#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public vector<T>
{
public:
    Stack(){};
    ~Stack(){};

    // Add other members only if necessary

    bool empty() const {
        if (std::vector<T>::size() == 0) {
            return true;
        }
        
        return false;
    }

    size_t size() const {
        return std::vector<T>::size();
    }

    void push(const T& item) {
        std::vector<T>::push_back(item);
        return;
    }

    void pop() {
        if (this->empty()) {
            throw std::underflow_error("STACK EMPTY");
        }

        else {
            std::vector<T>::pop_back();
            return;
        }
    }

    T const & top() const {
        if (this->empty()) {
            throw std::underflow_error("STACK EMPTY");
        }
        
        return this->back();
    }
};

/*
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    T const & top() const; // throws std::underflow_error if empty
    */


#endif