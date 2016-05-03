#include <cstdio> // printf
#include "tree.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "hash_table.h"
#include "hash_table_open_addressing.h"

// Test function
int main() {
    // Test Tree Class
    printf("Test of Tree:\n");
    Tree tree;
    Tree::TreeNode * tree_node_1 = new Tree::TreeNode(1);
    Tree::TreeNode * tree_node_2 = new Tree::TreeNode(2);
    Tree::TreeNode * tree_node_3 = new Tree::TreeNode(3);
    Tree::TreeNode * tree_node_0 = new Tree::TreeNode(0);
    tree.Insert(tree_node_1);
    tree.Insert(tree_node_2);
    tree.Insert(tree_node_3);
    tree.Insert(tree_node_0);
    printf("Minimum of tree is %i\n", tree.Minimum(tree.Top())->key);
    printf("Maximum of tree is %i\n", tree.Maximum(tree.Top())->key);
    printf("Successor of %i is %i\n", tree_node_2->key, tree.Successor(tree_node_2)->key);
    printf("Predecessor of %i is %i\n", tree_node_1->key, tree.Predecessor(tree_node_1)->key);
    tree.Remove(tree_node_0);
    tree.Remove(tree_node_1);
    tree.Remove(tree_node_3);
    tree.Remove(tree_node_2);
    delete tree_node_0;
    delete tree_node_1;
    delete tree_node_2;
    delete tree_node_3;
    
    // Test List Class
    printf("Test of List:\n");
    List list;
    List::ListNode * list_node_1 = new List::ListNode(1);
    List::ListNode * list_node_2 = new List::ListNode(2);
    List::ListNode * list_node_3 = new List::ListNode(3);
    list.Insert(list_node_1);
    list.Insert(list_node_3);
    list.Insert(list_node_2);
    printf("5 found list: %i. \n", list.Search(5) != list.dummy_);
    printf("2 found list: %i. \n", list.Search(2) != list.dummy_);
    list.Remove(list_node_2);
    printf("2 found list: %i. \n", list.Search(2) != list.dummy_);
    delete list_node_1;
    delete list_node_2;
    delete list_node_3;
    
    // Test Stack
    printf("Test of Stack:\n");
    Stack stack;
    stack.Push(5);
    stack.Push(3);
    while (!stack.IsEmpty()) {
        printf("%i ", stack.Pop());
    }
    printf("\n");
    
    // Test Queue
    printf("Test of Stack:\n");
    Queue queue;
    int i = 0;
    while(!queue.IsFull()) {
        queue.Enqueue(i++);
    }
    while(!queue.IsEmpty()) {
        printf("%i ", queue.Dequeue());
    }
    printf("\n");
    
    // Test HashTable
    printf("Test of HashTable:\n");
    HashTable table;
    table.Insert(1);
    printf("1 is found: %i\n", table.Search(1));
    table.Insert(2);
    table.Remove(1);
    printf("1 is found: %i\n", table.Search(1));
    printf("2 is found: %i\n", table.Search(2));
    printf("\n");
    
    // Test HashTableOpenAddressing
    printf("Test of HashTableOpenAddressing:\n");
    HashTableOpenAddressing table_open_addressing;
    table_open_addressing.Insert(1);
    table_open_addressing.Insert(1);
    table_open_addressing.Insert(2);
    printf("1 is found: %i\n", table_open_addressing.Exist(1));
    table_open_addressing.Remove(1);
    printf("1 is found: %i\n", table_open_addressing.Exist(1));
    printf("\n");
    return 0;
}