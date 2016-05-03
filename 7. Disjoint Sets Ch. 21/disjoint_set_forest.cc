template <typename T>
DisjointSetForest<T>::~DisjointSetForest() {
    for (int i = 0; i < sets_.size(); ++i) {
        delete sets_[i];
    }
}

// Creates a new node and add it to root list.
template <typename T>
typename DisjointSetForest<T>::HandleType DisjointSetForest<T>::MakeSet(ValueType x) {
    HandleType node_x = new DisjointSetForestNode(x);
    node_x->parent = node_x;
    node_x->rank = 0;
    sets_.push_back(node_x);
    return node_x;
}

// Compresses tree starting from node_x. Returns ancesstor node which is in root list.
template <typename T>
typename DisjointSetForest<T>::HandleType DisjointSetForest<T>::FindSet(HandleType node_x) {
    if (node_x->parent != node_x) {
        node_x->parent = FindSet(node_x->parent);
    }
    return node_x->parent;
}

// Calls Link to merge roots of node_x and node_y.
template <typename T>
void DisjointSetForest<T>::Union(HandleType node_x, HandleType node_y) {
    Link(FindSet(node_x), FindSet(node_y));
}

// Compares two tree and always link the one with less rank to the one with greater rank.
// If rank equals, increment rank by one.
template <typename T>
void DisjointSetForest<T>::Link(HandleType node_x, HandleType node_y) {
    if (node_x->rank > node_y->rank) {
        node_y->parent = node_x;
    }
    else {
        node_x->parent = node_y;
        if (node_x->rank == node_y->rank) {
            ++(node_y->rank);
        }
    }
}
