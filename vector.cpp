#include "vector.h"

using namespace std;

//Defaultkonstruktor (liefert einen leeren Vektor)---> DONE
Vector::Vector() {
    values = new double[min_length];
    length = 0;
    max_length = 10;
}

// Konstruktor mit Größenangabe (liefert einen Vektor mit Platz für vorgegebene Anzahl von Elementen)---> DONE
Vector::Vector(size_t lengh) {
    length = 0;
    max_length = lengh;
    values = new double[lengh];
}


// Konstruktor mit Initialisierungsliste (liefert einen Vektor mit spezifiziertem Inhalt)---> DONE
Vector::Vector(const initializer_list<double> list) {
    values = new double[list.size()];
    max_length = list.size();
    length = 0;
    for (const auto &value : list)
        values[length++] = value;
}

//Kopierkonstruktor (liefer einen Vektor mit demselben Inhalt)
Vector::Vector(const Vector &obj) {
    values = new double[obj.length];
    max_length = obj.max_length;
    length = obj.length;
    for (size_t i = 0; i < length; ++i) {
        values[i] = obj.values[i];
    }
}

//Destruktor
Vector::~Vector() {
    delete[] values;
}

//Kopierzuweisungoperator
Vector &Vector::operator=(const Vector &obj) {
    if (this == &obj)
        return *this;

    this->print();
//    obj.print();

    delete[] values;
    values = new double[obj.max_length];
    max_length = obj.max_length;
    length = obj.length;
    for (size_t i = 0; i < length; ++i) {
        values[i] = obj.values[i];
    }
//    vector.cpp:59:1: warning: control reaches end of non-void function [-Wreturn-type]
//}
//^
}

//Methoden
void Vector::print() const {
    if (length == 0) {
        cout << "[empty]";
    } else {
        for (size_t i = 0; i < length; ++i)
            cout << i << "[" << values[i] << "]--";

    }
    cout << "    length: " << length << " max_length: " << max_length << endl;

}

size_t Vector::size() {
    return length;
}

bool Vector::empty() {
    return length == 0;
}

void Vector::clear() {
    // може треба буде деструктор викликати як в АДС
    length = 0;
}

void Vector::reserve() {
    //create new
    double *valuesNew = new double[max_length * 2];
    //copy
    for (size_t i = 0; i < length; ++i) {
        valuesNew[i] = values[i];
    }//del old
    delete[] values;
    //put iinside new
    max_length = max_length * 2;
    values = valuesNew;
}

void Vector::shrink_to_fit() {
    //create new
    double *valuesNew = new double[length];
    //copy
    for (size_t i = 0; i < length; ++i) {
        valuesNew[i] = values[i];
    }//del old
    delete[] values;
    //put iinside new
    max_length = length;
    values = valuesNew;
}

void Vector::push_back(double elem) {
    if (max_length <= length)
        reserve();
    values[length++] = elem;
}

void Vector::pop_back() {
    length--;
}

double &Vector::operator[](size_t i) {
    if (i < length) {
        return values[i];
    } else {
        throw runtime_error("ERROR - Index called by [] operator was larger than length");
    }//тут тоже ерор бє
}
//    vector.cpp:130:1: warning: control reaches end of non-void function [-Wreturn-type]
//}