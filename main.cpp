#include <iostream>
#include "include/array.hpp"
#include "include/vector.hpp"


int main() {
    ds::vector<int> v;

v.push(10);
v.push(20);
v.push(30);
v.reserve(100);
v.pop();

std::cout << v[0] << '\n';
std::cout << v[1] << '\n';
std::cout << v[2] << '\n';
    return 0;
}
