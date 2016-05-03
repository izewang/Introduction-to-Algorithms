#include <utility> // std::move
#include <queue> // LevelorderTreeWalk()

// Firstly finds leaf position to insert node with TreeNode.key = key, then allocates memory for it
// if new node is created. New node is always set with color = kRED. Then calls function InsertFixup()
// to deal with situation where two kRED nodes are connected.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::Insert(const KeyType & key, const ValueType & value) {
    // Creates root_ node when tree is empty.
    if (root_.get() == nullptr) {
        root_.reset(new TreeNode(key, value));
        return;
    }
    HandleType cur_node = root_.get();
    HandleType parent_node = cur_node;
    // Finds leaf position for new node.
    while (cur_node != nullptr) {
        parent_node = cur_node;
        if (key < cur_node->key) {
            cur_node = (cur_node->left).get();
        }
        else if (key > cur_node->key) {
            cur_node = (cur_node->right).get();
        }
        else {
            cur_node->value = value; // If key exists, updates value.
            return;
        }
    }
    // Creates new TreeNodes at cur_node position.
    std::unique_ptr<TreeNode> p_node(new TreeNode(key, value));
    p_node->color = kRed;
    p_node->parent = parent_node;
    HandleType fix_node = p_node.get();
    if (parent_node->key > key) {
        parent_node->left = std::move(p_node);
    }
    else {
        parent_node->right = std::move(p_node);
    }
    // Fixs situation where both parent_node and fix_node are kRED.
    InsertFixup(fix_node);
}

// Calls Search(...) to find node with given key, if key exist calls DeleteNode(...) to delete that node then.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::Delete(const KeyType & key) {
    HandleType node = Search(key, root_.get());
    if (node == nullptr) {
        printf("Key not exist.\n");
        return;
    }
    DeleteNode(node);
}

// Searches node with given key by calling function Search(...), and returns bool variable indicating
// whether find any node.
template <typename KeyType, typename ValueType>
bool RedBlackTree<KeyType, ValueType>::Contains(KeyType key) const {
    return Search(key, root_.get()) != nullptr;
}

// Calls private member function to search node with given key.
template <typename KeyType, typename ValueType>
ValueType RedBlackTree<KeyType, ValueType>::Search(KeyType key) const {
    HandleType result = Search(key, root_.get());
    return result->value;
}

// Calls InorderTreeWalk(HandleType) to print out all node.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::InorderTreeWalk() const {
    printf("InorderTreeWalk()\n");
    InorderTreeWalk(root_.get());
    printf("\n");
}

// Using std::queue to keep track of current and next level nodes, prints out all
// nodes in zig-zag level order untill all nodes are printed.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::LevelorderTreeWalk() const {
    printf("LevelorderTreeWalk()\n");
    std::queue<HandleType> cur_level_nodes;
    if (root_.get() != nullptr) {
        cur_level_nodes.push(root_.get());
    }
    while (!cur_level_nodes.empty()) {
        std::queue<HandleType> next_level_nodes;
        while (!cur_level_nodes.empty()) {
            HandleType cur_node = cur_level_nodes.front();
            cur_level_nodes.pop();
            // If has none-nullptr children, push into next_level_nodes.
            if ((cur_node->left).get() != nullptr) {
                next_level_nodes.push((cur_node->left).get());
            }
            if ((cur_node->right).get() != nullptr) {
                next_level_nodes.push((cur_node->right).get());
            }
            // Prints out current node's data.
            printf("%i", cur_node->key);
            if (cur_node->color == kRed) {
                printf("(RED) ");
            }
            else {
                printf("(BLACK) ");
            }
        }
        // After prints out current level, copy next_level_nodes.
        cur_level_nodes = next_level_nodes;
        printf("\n");
    }
}

// LeftRotate subtree under current node, without changing color of nodes. node would point to right child
// of new subtree's root while original right child of node would take place of root of new created subtree.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::LeftRotate(HandleType node) {
    HandleType new_node = (node->right).release();
    if ((new_node->left).get() != nullptr) {
        new_node->left->parent = node;
    }
    node->right = std::move(new_node->left);
    if (node->parent == nullptr) {
        new_node->left = std::move(root_);
        root_.reset(new_node);
    }
    else if ((node->parent->left).get() == node) {
        new_node->left = std::move(node->parent->left);
        (node->parent->left).reset(new_node);
    }
    else {
        new_node->left = std::move(node->parent->right);
        (node->parent->right).reset(new_node);
    }
    new_node->parent = node->parent;
    node->parent = new_node;
}

// RightRotate subtree under current node, without changing color of nodes. node would point to left child
// of new subtree's root while original left child of node would take place of root of new created subtree.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::RightRotate(HandleType node) {
    HandleType new_node = (node->left).release();
    if ((new_node->right).get() != nullptr) {
        new_node->right->parent = node;
    }
    node->left = std::move(new_node->right);
    if (node->parent == nullptr) {
        new_node->right = std::move(root_);
        root_.reset(new_node);
    }
    else if ((node->parent->right).get() == node) {
        new_node->right = std::move(node->parent->right);
        (node->parent->right).reset(new_node);
    }
    else {
        new_node->right = std::move(node->parent->left);
        (node->parent->left).reset(new_node);
    }
    new_node->parent = node->parent;
    node->parent = new_node;
}

// From bottom to top, fix situation where both node and node->parent 's color are kRED.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::InsertFixup(HandleType node) {
    while (node->parent != nullptr && node->parent->color == kRed) {
        if (node->parent == (node->parent->parent->left).get()) {
            HandleType x = (node->parent->parent->right).get();
            if (x != nullptr && x->color == kRed) {
                node->parent->color = kBlack;
                node->parent->parent->color = kRed;
                x->color = kBlack;
                node = node->parent->parent;
            }
            else {
                if ((node->parent->right).get() == node) {
                    node = node->parent;
                    LeftRotate(node);
                }
                node->parent->color = kBlack;
                node->parent->parent->color = kRed;
                RightRotate(node->parent->parent);
            }
        }
        else { // Mirror symmetric cases, same as above, with left and right exchanged.
            HandleType x = (node->parent->parent->left).get();
            if (x != nullptr && x->color == kRed) {
                node->parent->color = kBlack;
                node->parent->parent->color = kRed;
                x->color = kBlack;
                node = node->parent->parent;
            }
            else {
                if ((node->parent->left).get() == node) {
                    node = node->parent;
                    RightRotate(node);
                }
                node->parent->color = kBlack;
                node->parent->parent->color = kRed;
                LeftRotate(node->parent->parent);
            }
        }
    }
    root_->color = kBlack; // node may be set as root after quit while loop, while its color = kRED.
}

template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::DeleteNode(HandleType node) {
    HandleType new_node = node;
    HandleType fix_node;
    Color new_node_original_color = new_node->color;
    // If both left and right child are empty.
    if ((node->left).get() == nullptr && (node->right).get() == nullptr) {
        // Deals with case where only one node is left.
        if (node == root_.get()) {
            root_.reset();
            return;
        }
        // Makes nil_ to be temporary right child of node, when
        if ((node->right).get() == nullptr) {
            nil_->parent = node;
            node->right = std::move(nil_);
        }
        fix_node = (node->right).get();
        Transplant(node, (node->right).get());
    }
    // If left child is empty.
    else if ((node->left).get() == nullptr) {
        // Only left child is empty.
        fix_node = (node->right).get();
        Transplant(node, (node->right).get());
    }
    else if ((node->right).get() == nullptr) {
        // Only right child is empty.
        fix_node = (node->left).get();
        Transplant(node, (node->left).get());
    }
    else {
        // Both chilren are not empty.
        // new_node would take place of node.
        new_node = Minimum((node->right).get());
        new_node_original_color = new_node->color;
        // If new_node->right is empty, make nil_ to be temporary child node of new_node.
        if ((new_node->right).get() == nullptr) {
            nil_->parent = new_node;
            new_node->right = std::move(nil_);
        }
        // fix_node is the position where one more kBLACK node needed to keep RedBlackTree structure.
        fix_node = (new_node->right).get();
        if (new_node->parent != node) {
            // Cuts new_node from its original position, and makes it as the right child of node.
            std::unique_ptr<TreeNode> dummy_node = std::move(new_node->parent->left);
            new_node->parent->left = std::move(new_node->right);
            fix_node->parent = new_node->parent;
            new_node->parent = node;
            node->right->parent = new_node;
            new_node->right = std::move(node->right);
            node->right = std::move(dummy_node);
        }
        // Replace node with new_node.
        new_node->color = node->color;
        node->left->parent = new_node;
        new_node->left = std::move(node->left);
        Transplant(node, new_node);
    }
    // If one kBLACK is removed after whole modification, calls DeleteFixup(...) to fix.
    if (new_node_original_color == kBlack) {
        DeleteFixup(fix_node);
    }
    // Removes temporary nil_ node from RedBlackTree structure. Temporary nil_node was needed by DeleteFixup.
    if (nil_.get() == nullptr) {
        if (fix_node == (fix_node->parent->left).get()) {
            nil_ = std::move(fix_node->parent->left);
        }
        else {
            nil_ = std::move(fix_node->parent->right);
        }
    }
}

// Replace to_node with from_node. Either to_node or from_node may be nullptr.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::Transplant(HandleType to_node, HandleType from_node) {
    // If from_node is nullptr, frees to_node.
    if (from_node == nullptr) {
        if (to_node->parent == nullptr) {
            root_ = nullptr;
        }
        else if ((to_node->parent->left).get() == to_node) {
            to_node->parent->left = nullptr;
        }
        else {
            to_node->parent->right = nullptr;
        }
        return;
    }
    // from_node is not leaf.
    // std::unique_ptr who owns from_node.
    auto & from_node_owner = ((from_node->parent->left).get() == from_node) ? (from_node->parent->left) : (from_node->parent->right);
    // Updates parent pointer of from_node.
    from_node_owner->parent = to_node->parent;
    // frees to_node's memory and updates unique_ptr of parent.
    if (to_node->parent == nullptr) {
        root_ = std::move(from_node_owner);
    }
    else if ((to_node->parent->left).get() == to_node) {
        to_node->parent->left = std::move(from_node_owner);
    }
    else {
        to_node->parent->right = std::move(from_node_owner);
    }
}

// Deals with cases where one less kBLACK node counted in the path from node to root_.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::DeleteFixup(HandleType node) {
    while (node != root_.get() && node->color == kBlack) {
        if (node == (node->parent->left).get()) {
            HandleType brother = (node->parent->right).get();
            if (brother->color == kRed) {
                brother->color = kBlack;
                node->parent->color = kRed;
                LeftRotate(node->parent);
                brother = (node->parent->right).get();
            }
            if ((brother->left == nullptr || brother->left->color == kBlack)
                && (brother->right == nullptr || brother->right->color == kBlack)) {
                brother->color = kRed;
                node = node->parent;
            }
            else {
                if (brother->right == nullptr || brother->right->color == kBlack) {
                    brother->left->color = kBlack;
                    brother->color = kRed;
                    RightRotate(brother);
                    brother = (node->parent->right).get();
                }
                brother->color = node->parent->color;
                node->parent->color = kBlack;
                brother->right->color = kBlack;
                LeftRotate(node->parent);
                node = root_.get();
            }
        }
        // Mirror cases, same as above, but with left and right exchanged.
        else {
            HandleType brother = (node->parent->left).get();
            if (brother->color == kRed) {
                brother->color = kBlack;
                node->parent->color = kRed;
                RightRotate(node->parent);
                brother = (node->parent->left).get();
            }
            if ((brother->left == nullptr || brother->left->color == kBlack)
                && (brother->right == nullptr || brother->right->color == kBlack)) {
                brother->color = kRed;
                node = node->parent;
            }
            else {
                if (brother->left == nullptr || brother->left->color == kBlack) {
                    brother->right->color = kBlack;
                    brother->color = kRed;
                    LeftRotate(brother);
                    brother = (node->parent->left).get();
                }
                brother->color = node->parent->color;
                node->parent->color = kBlack;
                brother->left->color = kBlack;
                RightRotate(node->parent);
                node = root_.get();
            }
        }
    }
    node->color = kBlack;
}

// Returns handle of most left node below node.
template <typename KeyType, typename ValueType>
typename RedBlackTree<KeyType, ValueType>::HandleType
RedBlackTree<KeyType, ValueType>::Minimum(HandleType node) const {
    HandleType parent = node;
    HandleType cur_node = node;
    while (cur_node != nullptr) {
        parent = cur_node;
        cur_node = (cur_node->left).get();
    }
    return parent;
}

// Recursively trasverses tree in order and return handle of node with given key. Returns nullptr
// if nothing is found.
template <typename KeyType, typename ValueType>
typename RedBlackTree<KeyType, ValueType>::HandleType
RedBlackTree<KeyType, ValueType>::Search(int key, HandleType node) const {
    if (node == nullptr || node->key == key) {
        return node;
    }
    else if (key < node->key) {
        return Search(key, (node->left).get());
    }
    else {
        return Search(key, (node->right).get());
    }
}

// Recursively prints data information in order.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::InorderTreeWalk(HandleType node) const {
    if (node == nullptr) {
        return;
    }
    // Prints left child.
    InorderTreeWalk((node->left).get());
    // Prints current node.
    printf("%i",node->key);
    if (node->color == kBlack) {
        printf("(BLACK) ");
    }
    else {
        printf("(RED) ");
    }
    // Prints right child.
    InorderTreeWalk((node->right).get());
}

// Recursively sets all unique_ptr to nullptr and frees memory.
template <typename KeyType, typename ValueType>
void RedBlackTree<KeyType, ValueType>::DeleteTree(std::unique_ptr<TreeNode> & node) {
    if (node.get() == nullptr) {
        return;
    }
    DeleteTree(node->left);
    DeleteTree(node->right);
    node.reset();
}
