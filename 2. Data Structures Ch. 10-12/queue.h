#ifndef queue_h
#define queue_h

#define QUEUE_LENGTH 100

// Simple Queue class implemented by fix size array. First-in-first-out.
// Usage:
//     Queue queue;
//     int i = 0;
//     while(!queue.IsFull()) {
//          queue.Enqueue(i);
//          i += 10;
//     }
//     while(!queue.IsEmpty()) {
//          printf("%i ", queue.Dequeue());
//     }
class Queue {
public:
    Queue() : empty_(true), head_(0), tail_(QUEUE_LENGTH - 1) {}
    // Returns whether queue is empty.
    bool IsEmpty() const;
    // Returns whether queue is full.
    bool IsFull() const;
    // Adds x into queue.
    void Enqueue(int x);
    // Removes first element in queue and returns its value.
    int Dequeue();
private:
    int nums_[QUEUE_LENGTH]; // stores element in queue.
    int head_, tail_; // index of first and last element in queue.
    bool empty_; // indicates queue is empty or not
};

#endif