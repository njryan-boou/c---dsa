#include <iostream>
#include "include/array.hpp"


int main() {
    Array<int, 5> arr;
    std::cout << arr[0] << '\n';
    std::cout << arr.front() << '\n';
    std::cout << arr.back() << '\n';  
    return 0;
}
