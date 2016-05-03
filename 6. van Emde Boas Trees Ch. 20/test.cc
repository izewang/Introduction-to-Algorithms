#include <iostream>
#include "van_emde_boas_tree.h"

int main() {
    VanEmdeBoasTree test(16);
    test.Insert(0);
    test.Insert(9);
    test.Insert(12);
    
    for (int i = 0; i < 16; ++i) {
        std::cout << "Member(" << i << ") = " << test.Member(i) << std::endl;
    }
    std::cout << "Minimum = " << test.Minimum() << std::endl;
    std::cout << "Maximum = " << test.Maximum() << std::endl;
    std::cout << "Successor(0) = " << test.Successor(0) << std::endl;
    std::cout << "Successor(10) = " << test.Successor(10) << std::endl;
    std::cout << "Successor(12) = " << test.Successor(12) << std::endl;
    std::cout << "Predecessor(0) = " << test.Predecessor(0) << std::endl;
    std::cout << "Predecessor(10) = " << test.Predecessor(10) << std::endl;
    
    test.Delete(12);
    for (int i = 0; i < 16; ++i) {
        std::cout << "Member(" << i << ") = " << test.Member(i) << std::endl;
    }
}

