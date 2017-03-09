#include <initializer_list>
#include <iostream>

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

    void print()const;

    size_t size();

    bool empty();

    void clear();

    void reserve();

    void shrink_to_fit();

    void push_back(double elem);

    void pop_back();

    double& operator[](size_t i);

    Vector& operator=(const Vector&);
//    size() (liefert die Anzahl der gespeicherten Elemente) -----> Done
//    empty() (liefert true, falls der Vektor leer ist, false sonst) -----> Done
//    clear() (löscht alle Elemente aus dem Vektor)  -----> Done
//    reserve() (Kapazität des Vektors wird vergrößert, falls nötig)  -----> Done
//    shrink_to_fit() (Kapazität des Vektors wird auf Anzahl der Elemente reduziert) -----> Done
//    push_back() (fügt ein neues Element am Ende hinzu) -----> Done
//    pop_back() (entfernt ein Element vom Ende) -----> Done
//    operator[] (const und nicht const; abgesichert;  ( вертає елемент по індексу -----> Done
};
