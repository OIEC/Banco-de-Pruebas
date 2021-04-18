#include <iostream>
#include <memory>

using namespace std;

constexpr int MAX_TREE = 100000000;
int next = 0;
Tree all_trees[MAX_TREE];

struct Tree {
    int key;

    shared_ptr<Tree> left;
    shared_ptr<Tree> right;

    Tree() : key(0), left(nullptr), right(nullptr) {}

    // constructor
    Tree(int key, Tree* left, Tree* right)
    : key(key), left(left), right(right)
    {}

    // destructor
};

//
Tree* insert(Tree* tree, int val) {
    if (tree == nullptr) {
        return new Tree(val, nullptr, nullptr);
    }

    if (val < tree->key) {
        tree->left = insert(tree->left, val);
    } else {
        tree->right = insert(tree->right, val);
    }
    return tree;
}

bool delete_node(Tree* tree, int val) {
    // if tree is null
    // return false
    //
    // tree->key == val ?
    //  borro el nodo

    if (val < tree->key) {
        return delete_node(tree->left, val);
    } else {
        return delete_node(tree->right, val);
    }
}

bool find(Tree* tree, int val) {
    if (tree == nullptr) {
        return false;
    }
    if (tree->key == val) {
        return true;
    }
    if (val < tree->key) {
        return find(tree->left, val);
    } else {
        return find(tree->right, val);
    }
}


int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int c;

    Tree* tree = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (find(tree, k - c)) {
            int c2 = k - c;
            if (c < c2) {
                cout << c << " " << c2 << endl;
            } else {
                cout << c2 << " " << c << endl;
            }
            return 0;
        }
        tree = insert(tree, c);
    }
}
