#include <cstdio> // printf
#include "hash_table_open_addressing.h"

HashTableOpenAddressing::HashTableOpenAddressing() {
    for (int i = 0; i < TABLE_LENGTH; ++i) {
        table_[i] = -1; // Marks all slots as empty.
    }
}

// Calls Search.
bool HashTableOpenAddressing::Exist(int key) const{
    return Search(key) != -1;
}

// Iterating over table by increment i, and inserts key into table when an empty or deleted
// slots is found before any key equals to key.
void HashTableOpenAddressing::Insert(int key) {
    for (int i = 0; i < TABLE_LENGTH; ++i) {
        int j = Hash(key, i);
        // If key existed in table, returns.
        if (table_[j] == key) {
            return;
        }
        // If slot j is empty or deleted, inserts key.
        if (table_[j] == -1 || table_[j] == -2) {
            table_[j] = key;
            return;
        }
    }
    printf("hash table overflow.\n");
}

// Calls Search to find index and marks as deleted.
void HashTableOpenAddressing::Remove(int key) {
    int j = Search(key);
    if (j != -1) {
        table_[j] = -2; // Marks as deleted.
    }
}

// Linear probing hash function
int HashTableOpenAddressing::Hash(int key, int i) const {
    return (key + i) % TABLE_LENGTH;
}

// Iterating over table by increment i of hash function, until an empty slot or key is found,
// or all numbers are checked.
int HashTableOpenAddressing::Search(int key) const {
    for (int i = 0; i < TABLE_LENGTH; ++i) {
        int j = Hash(key, i);
        if (table_[j] == key) {
            return j;
        }
        else if (table_[j] == -1) {
            return -1;
        }
    }
    return -1;
}
