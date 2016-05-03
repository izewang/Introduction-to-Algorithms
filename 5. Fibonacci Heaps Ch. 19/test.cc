#include <iostream>
#include "fibonacci_heap.h"

int main() {
    //test
    FibonacciHeap<int> heap;
    heap.Insert(2);
    std::cout<<heap.Minimum()<<std::endl;
    heap.Insert(1);
    FibonacciHeap<int>::HandleType node = heap.Insert(3);
    std::cout<<heap.Minimum()<<std::endl;
    heap.PrintTree();
    
    heap.DecreaseKey(node, 0);
    std::cout<<heap.Minimum()<<std::endl;
    
    heap.Delete(node);
    heap.PrintTree();
    
    heap.ExtractMin();
    std::cout<<heap.Minimum()<<std::endl;
    heap.PrintTree();
    
    FibonacciHeap<int> heap2;
    heap2.Insert(5);
    heap2.Insert(-1);
    heap.Union(heap2);
    std::cout<<heap.Minimum()<<std::endl;
    heap.PrintTree();
    
    heap.ExtractMin();
    std::cout<<heap.Minimum()<<std::endl;
    heap.PrintTree();
    
}