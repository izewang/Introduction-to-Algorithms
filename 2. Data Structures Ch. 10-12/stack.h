#ifndef stack_h
#define stack_h

#define STACK_LENGTH 100

// A class of stack implemented by fix sized array of int. Numbers stored in
// last-in-first-out fashion.
// Usage:
//     Stack stack;
//     stack.Push(5);
//     stack.Push(3);
//     while (!stack.IsEmpty()) {
//          printf("%i ", stack.Pop());
//     }
class Stack {
public:
    Stack() : top_(-1) {}
    // Returns boolean variable indicating whether Stack is empty.
    bool IsEmpty() const ;
    // Returns boolean variable indicating whether Stack is full.
    bool IsFull() const;
    // Adds an element at the top to stack.
    void Push(int x);
    // Returns top element of stack and also removes it.
    int Pop();
private:
    int nums_[STACK_LENGTH]; // array to store int numbers.
    int top_; // index before place for next insertion.
};

#endif