#include <iostream>
#include "include/array.hpp"
#include "include/vector.hpp"
#include "include/list.hpp"


int main() {
    ds::list<int> nums;

    nums.push_back(10);
    nums.push_back(20);
    nums.push_front(5);

    std::cout << nums.front() << '\n'; // 5
    std::cout << nums.back() << '\n';  // 20
    std::cout << nums[1] << '\n';      // 10

    ds::list<int> copy = nums;
    copy[1] = 99;

    std::cout << nums[1] << '\n';      // 10
    std::cout << copy[1] << '\n';      // 99

    nums.pop_front();
    nums.pop_back();

    std::cout << nums.front() << '\n'; // 10
}
