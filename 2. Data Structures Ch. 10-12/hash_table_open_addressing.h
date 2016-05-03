#ifndef hash_table_open_addressing_h
#define hash_table_open_addressing_h

#define TABLE_LENGTH 701

// Open addressing hash table with linear probing hash function. Element is stored in an
// adjacent array of fixed size. Takes O(1) in average for insert, remove and search.
// Usage:
//     HashTableOpenAddressing table;
//     table.Insert(1);
class HashTableOpenAddressing {
public:
    HashTableOpenAddressing();
    // Returns boolean variable indicating whether key exists in hash table.
    bool Exist(int key) const;
    // Inserts key into hash table, if not found in hash table
    void Insert(int key);
    // Removes key from hash tables, if found any.
    void Remove(int key);
private:
    // Hash function interating all slots once when incrementing i.
    int Hash(int key, int i) const;
    // Returns index of key in table_, and returns -1 if not found.
    int Search(int key) const;
    int table_[TABLE_LENGTH]; // stores numbers in hash table.
};

#endif