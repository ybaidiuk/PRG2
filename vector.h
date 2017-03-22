#include <initializer_list>
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class Vector {
public:
    class Constiterator;

    class Iterator;

    using value_type = T;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using reference = T &;
    using const_reference = const T &;
    using pointer = T *;
    using const_pointer = const T *;
    using iterator = Iterator;
    using const_iterator = Constiterator;

    static constexpr size_t min_length = 10;
    size_t max_length;
    size_t length;
    T *values;


//Defaultkonstruktor (liefert einen leeren Vektor)---> DONE
    Vector() {
        values = new T[min_length];
        length = 0;
        max_length = 10;
    }

// Konstruktor mit Größenangabe (liefert einen Vektor mit Platz für vorgegebene Anzahl von Elementen)---> DONE
    Vector(size_t lengh) {
        length = 0;
        max_length = lengh;
        values = new T[lengh];
    }


// Konstruktor mit Initialisierungsliste (liefert einen Vektor mit spezifiziertem Inhalt)---> DONE
    Vector(const initializer_list<T> list) {
        values = new T[list.size()];
        max_length = list.size();
        length = 0;
        for (const auto &value : list)
            values[length++] = value;
    }

//Kopierkonstruktor (liefer einen Vektor mit demselben Inhalt)
    Vector(const Vector &obj) {
        values = new T[obj.length];
        max_length = obj.max_length;
        length = obj.length;
        for (size_t i = 0; i < length; ++i) {
            values[i] = obj.values[i];
        }
    }

//Destruktor
    ~Vector() {
        delete[] values;
    }

//Kopierzuweisungoperator
    Vector &operator=(const Vector &obj) {
        if (this == &obj)
            return *this;

        delete[] values;
        values = new T[obj.max_length];
        max_length = obj.max_length;
        length = obj.length;
        for (size_t i = 0; i < length; ++i) {
            values[i] = obj.values[i];
        }

        return *this;
    }

//Methoden
    ostream &print(ostream& os) const {
        if (length == 0) {
            cout << "[empty]";
        } else {
            for (size_t i = 0; i < length; ++i)
                cout << i << "[" << values[i] << "]--";

        }
        cout << "    length: " << length << "  size: " << max_length << endl;
        return os;
    }

    size_t size() {
        return length;
    }

    bool empty() {
        return length == 0;
    }

    void clear() {
        // може треба буде деструктор викликати як в АДС
        length = 0;
    }

    void reserve() {
        //create new
        T *valuesNew = new T[max_length * 2];
        //copy
        for (size_t i = 0; i < length; ++i) {
            valuesNew[i] = values[i];
        }//del old
        delete[] values;
        //put iinside new
        max_length = max_length * 2;
        values = valuesNew;
    }

    void shrink_to_fit() {
        //create new
        T *valuesNew = new T[length];
        //copy
        for (size_t i = 0; i < length; ++i) {
            valuesNew[i] = values[i];
        }//del old
        delete[] values;
        //put iinside new
        max_length = length;
        values = valuesNew;
    }

    void push_back(T elem) {
        if (max_length <= length)
            reserve();
        values[length++] = elem;
    }

    void pop_back() {
        length--;
    }

    T &operator[](size_t i) {
        if (i < length) {
            return values[i];
        } else {
            throw runtime_error("ERROR - Index called by [] operator was larger than length");
        }
    }


    /**  ITERATORS  **/



    class Constiterator {
        T *ptr;
    public:
        using value_type = value_type;
        using difference_type = difference_type;
        using reference = reference;
        using pointer = pointer;
        using iterator_category = std::forward_iterator_tag;


        Constiterator(T *new_const_iterator) {
            this->ptr = new_const_iterator;
        }

        Constiterator(const Vector &new_vector) {
            this->ptr = (new_vector.begin()).ptr;
        }


        const Constiterator &operator++() {
            this->ptr = this->ptr + 1;
            return *this;
        }

        bool operator!=(const Constiterator &src) const {
            return this->ptr != src.ptr;
        }

        const T &operator*() const {
            return *ptr;
        }

        const T &operator*() {
            return *ptr;
        }

        bool operator==(const Constiterator &src) const {
            return this->ptr == src.ptr;
        }

//Operator ++
        Constiterator operator++(int) {
            Constiterator old{*this};
            ++*this;
            return old;
        }

//Retouniert den Pointer, wohin Iterator zeigt.
        const T *operator->() {
            return ptr;
        }


        friend difference_type operator-(const Constiterator &lop,
                                         const Constiterator &rop) {
            return lop.ptr - rop.ptr;
        }
    };


    class Iterator {
        T *ptr;
    public:
        using value_type = value_type;
        using difference_type = difference_type;
        using reference = reference;
        using pointer = pointer;
        using iterator_category = std::forward_iterator_tag;


        Iterator(T *new_iterator) {
            this->ptr = new_iterator;
        }

        Iterator(Vector &new_vector) {
            this->ptr = (new_vector.begin()).ptr;
        }

        const Iterator &operator++() {  // ++Iterator
            this->ptr = this->ptr + 1;
            return *this;
        }
//        Iterator operator++(int){ //  iterator++
//            Iterator old{*this};
//            ++*this;
//            return old;
//        }

        bool operator!=(const Iterator &src) const {
            return this->ptr != src.ptr;
        }


        bool operator==(const Iterator &src) const { return this->ptr == src.ptr; }

        T &operator*() {
            return *ptr;
        }

        //?
        const T &operator*() const {
            return *ptr;
        }

        const T *operator->() {
            return ptr;
        }

        operator Constiterator() {
            return Constiterator(ptr);
        }
    };

    Iterator begin() { return Iterator(values); }

    Iterator end() { return Iterator(values + length); }

    const Constiterator begin() const { return Constiterator(values); }

    const Constiterator end() const { return Constiterator(values + length); }


    iterator erase(const_iterator pos) { // Vector v = {1,2,3,4,5}
        auto diff = pos - begin();
        if (diff < 0 || static_cast<size_type>(diff) >= length)
            throw runtime_error("Iterator out of bounds");
        size_type current{static_cast<size_type>(diff)};
        for (; current < length - 1; ++current)
            values[current] = values[current + 1];
        --length;
        return iterator{values + current};
    }

//muss noch von neiue Folie nehmen
    iterator insert(const_iterator pos,
                    const_reference val) {
        auto diff = pos-begin();
        if (diff<0 || static_cast<size_type>(diff)>length)
            throw runtime_error("Iterator out of bounds");
        size_type current{static_cast<size_type>(diff)};
        if (length>=max_length)
            reserve(); //max_length*2+10, wenn Ihr Container max_length==0 erlaubt
        for (size_t i {length}; i-->current;)
            values[i+1]=values[i];
        values[current]=val;
        ++length;
        return iterator{values+current};
//        return Iterator(values+current);
    }


};

template<typename T>
ostream &operator<<(ostream &os, const Vector<T> &vector) {
    return vector.print(os);
}
