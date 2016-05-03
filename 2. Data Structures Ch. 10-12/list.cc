#include "list.h"

List::List() {
    dummy_ = new ListNode(-1);
    dummy_->next = dummy_;
    dummy_->prev = dummy_;
}

List::~List() {
    delete dummy_;
}

List::HandleType List::Front() const {
    return dummy_->next;
}

List::HandleType List::Back() const {
    return dummy_->prev;
}

// Compares nodes' key with key from first node to last node until reaches dummy_ or found.
List::HandleType List::Search(int key) const {
    HandleType cur = dummy_->next;
    while(cur != dummy_ && cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

// Adds x into list in position right after dummy_.
void List::Insert(HandleType x) {
    dummy_->next->prev = x;
    x->next = dummy_->next;
    x->prev = dummy_;
    dummy_->next = x;
}

// Connects nodes before and after x.
void List::Remove(HandleType x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
}
