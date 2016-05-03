#ifndef hash_table_h
#define hash_table_h

#include "list.h"

#define TABLE_LENGTH 701

// Simple Hash Table implemented by fixed size array of list, used to store integers.
// in O(1) time. Use mod operation as hash function.
// Usage:
//     HashTable table;
//     table.Insert(1);
//     table.Insert(2);
//     table.Remove(2);
//     table. Search(2);
class HashTable {
public:
    // Returns boolean variable indicating whether element is in hash table.
    bool Search(int key) const;
    // Adds key into hash table.
    void Insert(int key);
    // Removes key from hash table.
    void Remove(int key);
private:
    // Returns hash number.
    int Hash(int key) const;
    List table_[TABLE_LENGTH]; // stores numbers in array of list.
};

#endif