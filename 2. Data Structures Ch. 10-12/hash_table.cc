#include "hash_table.h"

// Hash function using mod operation
int HashTable::Hash(int key) const {
    return key % TABLE_LENGTH;
}

// Uses List.Search to find key
bool HashTable::Search(int key) const {
    int hash_val = Hash(key);
    return table_[hash_val].Search(key) != table_[hash_val].dummy_;
}

// Find index by Hash function and calls List.Insert to insert element when it's not in list.
void HashTable::Insert(int key) {
    int hash_val = Hash(key);
    if (table_[hash_val].Search(key) == table_[hash_val].dummy_) {
        table_[hash_val].Insert(new List::ListNode(key));
    }
}

// Find index in array by Hash function and calls List.Remove to remove element if it's found.
void HashTable::Remove(int key) {
    int hash_val = Hash(key);
    List::HandleType tmp_node = table_[hash_val].Search(key);
    if (tmp_node != table_[hash_val].dummy_) {
        table_[hash_val].Remove(tmp_node);
    }
}
