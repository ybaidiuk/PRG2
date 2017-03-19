#include "vector.h"


using namespace std;

int main() {

    const Vector v{1, 2, 2.5, 3, 5};
    for (auto &elem : v)
        elem = 7;
    for (double elem: v)
        cout << elem << ' ';
    cout << '\n';

//    Vector v1{1, 2, 3};
//    for (auto &elem : v1)
//        elem = 7;
//
//    for (double i : v1) {
//        cout << i << endl;
//    }
//    for (double elem: v1)
//        cout << elem << ' ';





//    int *array = new int[3];
//    array[0] = 1;
//    array[1] = 2;
//    array[2] = 3;
//
//    int *p = array;
//
//
//    cout << p[0];
//    cout << array[1];
//    cout << array[2];
//
//


//    v1.print();
//    v1.insert(0,99);
    return 0;
}

//void print() const;
//
//size_t size();
//
//bool empty();
//
//void clear();
//
//void reserve();
//
//void shrink_to_fit();
//
//void push_back(double elem);
//
//void pop_back();