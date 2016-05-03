#include <iostream>
#include "disjoint_set_forest.h"

int main() {
    DisjointSetForest<int> set;
    auto p1 = set.MakeSet(0);
    auto p2 = set.MakeSet(1);
    set.Union(p1, p2);
    auto q1 = set.MakeSet(2);
    auto q2 = set.MakeSet(3);
    set.Union(q1, q2);
    std::cout << "p1 == p2 :" << bool(set.FindSet(p1) == set.FindSet(p2)) << std::endl;
    std::cout << "q1 == q2 :" << bool(set.FindSet(q1) == set.FindSet(q2)) << std::endl;
    std::cout << "p1 == q1 :" << bool(set.FindSet(p1) == set.FindSet(q1)) << std::endl;
    std::cout << "p1 == q2 :" << bool(set.FindSet(p1) == set.FindSet(q2)) << std::endl;
    set.Union(p1, q2);
    std::cout << "p1 == q1 :" << bool(set.FindSet(p1) == set.FindSet(q1)) << std::endl;
    std::cout << "p1 == q2 :" << bool(set.FindSet(p1) == set.FindSet(q2)) << std::endl;
}