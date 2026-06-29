#pragma once

namespace ds {

template<typename T, int L>
class array
{
    private:
        T data[L];

    public:
        // index operator
        T& operator[](int index) {
            return data[index];
        }

        int front() {
            return data[0];
        }

        int back() {
            return data[L];
        }



        // get size
        int size() {
            return L;
        }
};

}