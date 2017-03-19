#include <initializer_list>
#include <iostream>
#include <stdexcept>

using namespace std;

class Vector {
public:

    using value_type = double;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = double&;
    using const_reference = const double&;
    using pointer = double*;
    using const_pointer = const double*;
    using iterator = double*;
    using const_iterator = const double*;

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

    void insert(size_t position, double elem);
//    iterator erase(const_iterator pos);


    class Iterator { //automatisch friend von Vector
        double *ptr;
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using reference = Vector::reference;
        using pointer = Vector::pointer;
        using iterator_category = std::forward_iterator_tag;
    public:
        Iterator(double *p) {
            ptr = p;
        };


        const Iterator &operator++() {
            ptr++;
            return *this;
        };



        bool operator!=(const Iterator &obj) {

            return ptr != obj.ptr;
        };

        bool operator==(const Iterator &obj) {
            return ptr == obj.ptr;
        };

        double &operator*() {
            return *ptr;
        };

        const double &operator*() const {
            return *ptr;
        };


    };

    Iterator begin() { return Iterator(values); }

    Iterator end() { return Iterator(values + length); }

    const Iterator begin() const { return Iterator(values); }

    const Iterator end() const { return Iterator(values + length); }
};
