#include "vector.h"


using namespace std;

int main() {
    Vector v1{1, 2, 3};

    v1.print();
    cout << v1.size() << endl;
    cout << v1.empty() << endl;
    v1.print();
    v1.clear();
    cout << v1.empty() << endl;
    v1.push_back(1.1);
    v1.push_back(1.2);
    v1.print();
    v1.pop_back();
    v1.print();
    v1.reserve();
    v1.print();
    v1.shrink_to_fit();
    v1.print();

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