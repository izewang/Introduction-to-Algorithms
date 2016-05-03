#include <cstdio> // printf
#include "stack.h"

bool Stack::IsEmpty() const {
    return top_ == -1;
}

bool Stack::IsFull() const {
    return top_ == STACK_LENGTH - 1;
}

// If stack is not full, adds one element at the last and increment top_.
void Stack::Push(int x) {
    if (IsFull()) {
        printf("overflow.\n");
        return;
    }
    nums_[++top_] = x;
}

// If stack is not empty, returns last element stored and decrement top_.
int Stack::Pop() {
    if (IsEmpty()) {
        printf("underflow.\n");
        return -1;
    }
    return nums_[top_--];
}
