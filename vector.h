#include <initializer_list>
#include <iostream>
#include <stdexcept>

using namespace std;

class Vector {
public:

    static constexpr size_t min_length = 10;
    size_t max_length;
    size_t length;
    double *values;

    Vector();

    Vector(size_t);

    Vector(const initializer_list<double> list);


    Vector(const Vector &obj);

    ~Vector();

    void print() const;

    size_t size();

    bool empty();

    void clear();

    void reserve();

    void shrink_to_fit();

    void push_back(double elem);

    void pop_back();

    double &operator[](size_t i);

    Vector &operator=(const Vector &obj);
};
