#include <initializer_list>
#include <iostream>
#include <stdexcept>

using namespace std;

class Vector {
public:
    class Constiterator;

    using value_type = double;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = double &;
    using const_reference = const double &;
    using pointer = double *;
    using const_pointer = const double *;
    using iterator = double *;
    using const_iterator = Constiterator;

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




    iterator erase(const_iterator);
    iterator insert(const_iterator, const_reference);
    class Constiterator {
        double* ptr;
    public:
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using reference = Vector::reference;
        using pointer = Vector::pointer;
        using iterator_category = std::forward_iterator_tag;

        Constiterator(double *); //konstruktor
        Constiterator(const Vector &); //Konstruktor 2
        const Constiterator &operator++(); //Ueberladung
        Constiterator operator++(int); //Ueberaldung2
        bool operator!=(const Constiterator &) const; //Vergleich
        const double &operator*(); //Ueberladung
        const double &operator*() const; //Ueberladung 2
        bool operator==(const Constiterator &) const; //Vergleich 2
        const double *operator->(); //retuniert pointer
        //Operator -. Globale Variable
        friend difference_type operator-(const Constiterator &, const Constiterator &);
    };


    class Iterator {
        double* ptr;
    public:
        using value_type = Vector::value_type;
        using difference_type = Vector::difference_type;
        using reference = Vector::reference;
        using pointer = Vector::pointer;
        using iterator_category = std::forward_iterator_tag;


        Iterator(double *); //konstruktor
        Iterator(Vector &); //Konstruktor2
        const Iterator &operator++(); //Ueberladung
        Iterator operator++(int); //Ueberaldung2
        bool operator!=(const Iterator &) const; //Vergleich
        bool operator==(const Iterator &) const; //Vergleich 2
        double &operator*(); //Ueberladung
        const double &operator*() const; //Ueberladung 2
        const double *operator->(); //retuniert pointer
        operator Constiterator();
    };

    Iterator begin();
    Iterator end();
    const Constiterator begin() const;
    const Constiterator end() const;
};
