#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

namespace ds {

template<typename T>
class vector {

    private:
        T* data;
        size_t _size;
        size_t _capacity;
    
    public:
        vector() {
            data = nullptr;
            _size = 0;
            _capacity = 0;
        }

        // copy constructor
        vector(const vector& other) {
            _size = other._size;
            _capacity = other._capacity;

            data = new T[_capacity];

            for (size_t i = 0; i < _size; ++i) {
                data[i] = other.data[i];
            }
        }

        // move constructor
        vector(vector&& other) {
            data = other.data;
            _size = other._size;
            _capacity = other._capacity;

            other.data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }

        // move assignment 
        vector& operator=(vector&& other) {
            if (this == &other) {
                return *this;
            }

            delete[] data;

            data = other.data;
            _size = other._size;
            _capacity = other._capacity;

            other.data = nullptr;
            other._size = 0;
            other._capacity = 0;

            return *this;
        }

        vector& operator=(const vector& other) {
            if (this == &other) {
                return *this;
            }

            delete[] data;

            _size = other._size;
            _capacity = other._capacity;

            if (_capacity > 0) {
                data = new T[_capacity];

                for (size_t i = 0; i < _size; ++i) {
                    data[i] = other.data[i];
                }
            }
            else {
                data = nullptr;
            }

            return *this;
        }

        // destructor
        ~vector() {
            delete[] data;
        }

        T& operator[](size_t index) {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }
            
            return data[index];
        }

        const T& operator[](size_t index) const {
            if (index >= _size) {
                throw std::out_of_range("Index out of range");
            }

            return data[index];
        }

        void push(const T& value) {
            if (_size == _capacity) {
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            }

            data[_size] = value;
            ++_size;
        }

        void reserve(size_t new_capacity) {
            if (new_capacity <= _capacity)
                return;

            T* new_data = new T[new_capacity];

            for (size_t i = 0; i < _size; ++i) {
                new_data[i] = data[i];
            }

            delete[] data;

            data = new_data;
            _capacity = new_capacity;
        }

        void pop() {
            --_size;
        }

        void clear() {
            _size = 0;
        }

        size_t size()  const {
            return _size;
        }

        size_t capacity() const {
            return _capacity;
        }
};

}