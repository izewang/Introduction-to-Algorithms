#ifndef list_h
#define list_h

// A double linked list class, consisting a number of linked nodes. Each node has a pointer to
// previous node and a pointer to next node. Memory allocation is done outside class.
// Usage:
//     List list;
//     List::ListNode * node_1 = new List::ListNode(1);
//     list.Insert(node_1);
class List {
public:
    struct ListNode {
        ListNode(int key) : key(key), prev(nullptr), next(nullptr) {}
        ListNode * prev, * next;
        int key;
    };
    typedef ListNode * HandleType;
    
    List();
    List(List &&) = default;
    List(const List &) = delete;
    List & operator=(List &&) = default;
    List & operator=(const List &) = delete;
    ~List();
    
    // Returns handle of first node in list.
    HandleType Front() const;
    // Returns handle of last node in list.
    HandleType Back() const;
    // Returns node with key value equals to key. returns dummy_ when nothing found.
    HandleType Search(int key) const;
    // Inserts x from front.
    void Insert(HandleType x);
    // Removes node given its handle
    void Remove(HandleType x);
    
    HandleType dummy_; // dummy node
};

#endif