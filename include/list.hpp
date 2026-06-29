#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>

namespace ds {

template<typename T>
class list {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;

        Node(const T& value)
            : value(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    std::size_t _size;

public:
    list()
        : head(nullptr), tail(nullptr), _size(0) {}

    ~list() {
        clear();
    }

    list(const list& other)
        : head(nullptr), tail(nullptr), _size(0) {
        Node* current = other.head;

        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }
    }

    list& operator=(const list& other) {
        if (this == &other) {
            return *this;
        }

        clear();

        Node* current = other.head;

        while (current != nullptr) {
            push_back(current->value);
            current = current->next;
        }

        return *this;
    }

    list(list&& other) noexcept
        : head(other.head),
          tail(other.tail),
          _size(other._size) {
        other.head = nullptr;
        other.tail = nullptr;
        other._size = 0;
    }

    list& operator=(list&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        clear();

        head = other.head;
        tail = other.tail;
        _size = other._size;

        other.head = nullptr;
        other.tail = nullptr;
        other._size = 0;

        return *this;
    }

    void push_back(const T& value) {
        Node* node = new Node(value);

        if (empty()) {
            head = node;
            tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        ++_size;
    }

    void push_front(const T& value) {
        Node* node = new Node(value);

        if (empty()) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        ++_size;
    }

    void pop_back() {
        if (empty()) {
            throw std::out_of_range("pop_back on empty list");
        }

        Node* old_tail = tail;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete old_tail;
        --_size;
    }

    void pop_front() {
        if (empty()) {
            throw std::out_of_range("pop_front on empty list");
        }

        Node* old_head = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete old_head;
        --_size;
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("front on empty list");
        }

        return head->value;
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("front on empty list");
        }

        return head->value;
    }

    T& back() {
        if (empty()) {
            throw std::out_of_range("back on empty list");
        }

        return tail->value;
    }

    const T& back() const {
        if (empty()) {
            throw std::out_of_range("back on empty list");
        }

        return tail->value;
    }

    T& operator[](std::size_t index) {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }

        Node* current = head;

        for (std::size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->value;
    }

    const T& operator[](std::size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("index out of range");
        }

        Node* current = head;

        for (std::size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        return current->value;
    }

    void clear() {
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    bool empty() const {
        return _size == 0;
    }

    std::size_t size() const {
        return _size;
    }
};

}