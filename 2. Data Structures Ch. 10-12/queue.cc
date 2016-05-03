#include <cstdio> // printf
#include "queue.h"

bool Queue::IsEmpty() const {
    return empty_;
}

bool Queue::IsFull() const {
    return (!empty_ && ((tail_ == QUEUE_LENGTH - 1 && head_ == 0) || (tail_ + 1 == head_)));
}

// Moves tail_ to next slot and adds elements to tail_.
void Queue::Enqueue(int x) {
    // Places tail_ to new index of enqueued element.
    if (tail_ == QUEUE_LENGTH - 1) {
        tail_ = 0;
    }
    else {
        ++tail_;
    }
    // If queue is full, send error message
    if (tail_ == head_ && !empty_) {
        printf("overflow.\n");
        // Rolls back tail_
        if (tail_ == 0) {
            tail_ = QUEUE_LENGTH - 1;
        }
        else {
            --tail_;
        }
        return;
    }
    // else, insert x into nums_
    nums_[tail_] = x;
    empty_ = false;
}

// Moves head_ to next slot and updates empty_ valuable.
int Queue::Dequeue(){
    if (empty_) {
        printf("underflow.\n");
        return -1;
    }
    // Only one element in queue.
    if (head_ == tail_) {
        empty_ = true;
    }
    int x = nums_[head_];
    // Moves head_ to one next slot.
    if (head_ == QUEUE_LENGTH - 1) {
        head_ = 0;
    }
    else {
        ++head_;
    }
    return x;
}
