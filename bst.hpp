#pragma once

#include <cstddef>

namespace ds {

template<typename T>
class bst {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(const T& value)
            : value(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    std::size_t _size;

public:
    bst()
        : root(nullptr), _size(0) {}

    ~bst() {
        clear(root);
    }

    void insert(const T& value) {
        root = insert(root, value);
    }

    bool contains(const T& value) const {
        return contains(root, value);
    }

    std::size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

private:

    Node* insert(Node* node, const T& value) {

        if (node == nullptr) {
            ++_size;
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else if (value > node->value) {
            node->right = insert(node->right, value);
        }

        return node;
    }

    bool contains(Node* node, const T& value) const {

        if (node == nullptr)
            return false;

        if (value == node->value)
            return true;

        if (value < node->value)
            return contains(node->left, value);

        return contains(node->right, value);
    }

    void clear(Node* node) {

        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);

        delete node;
    }
};

}