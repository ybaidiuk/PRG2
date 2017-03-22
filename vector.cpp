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

    delete[] values;
    values = new double[obj.max_length];
    max_length = obj.max_length;
    length = obj.length;
    for (size_t i = 0; i < length; ++i) {
        values[i] = obj.values[i];
    }

    return *this;
}

//Methoden
void Vector::print() const {
    if (length == 0) {
        cout << "[empty]";
    } else {
        for (size_t i = 0; i < length; ++i)
            cout << i << "[" << values[i] << "]--";

    }
    cout << "    length: " << length << "  size: " << max_length << endl;

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
    }
}









/** Iterator **/

//Vektor+Iterator
Vector::Iterator Vector::begin() {return Iterator(values);}
Vector::Iterator Vector::end(){return Iterator (values+length);}
const Vector::Constiterator Vector::begin() const {return Constiterator(values);}
const Vector::Constiterator Vector::end() const {return Constiterator (values+length);}
//Iterator

//Kostruktor eines Iterators
Vector:: Iterator::Iterator(double* new_iterator) {
    this->ptr=new_iterator;
}

//Konstruktor eines Iterators 2
Vector:: Iterator::Iterator(Vector& new_vector) {
    this->ptr=(new_vector.begin()).ptr;
}


//Ueberladung von operator ++
const Vector::Iterator& Vector::Iterator::operator++() {
    this->ptr=this->ptr+1;
    return *this;
}

//Ueberladung von operator !=
bool Vector::Iterator::operator!=(const Iterator& src)const{
    return this->ptr != src.ptr;
}

//Ueberladung von operator *
double& Vector::Iterator::operator*(){
    return *ptr;
}

//Ueberladung von operator *
const double& Vector::Iterator:: operator*() const{
    return *ptr;
}
bool Vector::Iterator::operator==(const Iterator& src)const{
    return this->ptr == src.ptr;
}

Vector::Iterator Vector::Iterator::operator++(int){
    Iterator old{*this};
    ++*this;
    return old;
}

//Retouniert den Poniter, wohin Iterator zeigt.
const double* Vector::Iterator::operator->(){
    return ptr;
}




/** const_iterator **/


Vector::Constiterator::Constiterator(double*new_const_iterator){
    this->ptr=new_const_iterator;
}

Vector::Constiterator::Constiterator(const Vector& new_vector){
    this->ptr=(new_vector.begin()).ptr;
}


const Vector::Constiterator& Vector::Constiterator::operator++() {
    this->ptr=this->ptr+1;      //aufg1: ptr-1
    return *this;
}

bool Vector::Constiterator::operator!=(const Constiterator& src)const{
    return this->ptr != src.ptr;
}

const double& Vector::Constiterator:: operator*() const{
    return *ptr;
}
const double& Vector::Constiterator:: operator*() {
    return *ptr;
}

bool Vector::Constiterator::operator==(const Constiterator& src)const{
    return this->ptr == src.ptr;
}

//Operator ++
Vector::Constiterator Vector::Constiterator::operator++(int){
    Constiterator old{*this};
    ++*this;
    return old;
}

//Retouniert den Pointer, wohin Iterator zeigt.
const double* Vector::Constiterator::operator->(){
    return ptr;
}
//typUmwandlung
Vector::Iterator::operator Constiterator(){
    return Constiterator(ptr);
}

//Operator -
Vector::difference_type operator-(const Vector::Constiterator& lop,
                                  const Vector::Constiterator& rop) {
    return lop.ptr-rop.ptr;
}

Vector::iterator Vector::erase(Vector::const_iterator pos) { // Vector v = {1,2,3,4,5}
    auto diff = pos-begin();
    if (diff<0 || static_cast<size_type>(diff)>=length)
        throw runtime_error("Iterator out of bounds");
    size_type current{static_cast<size_type>(diff)};
    for (; current<length-1; ++current)
        values[current]=values[current+1];
    --length;
    return Vector::iterator{values+current};
}


Vector::iterator Vector::insert(Vector::const_iterator pos,
                                Vector::const_reference val) {
    auto diff = pos-begin();
    if (diff<0 || static_cast<size_type>(diff)>length)
        throw runtime_error("Iterator out of bounds");
    size_type current{static_cast<size_type>(diff)};
    if (length>=max_length)
        reserve(); //max_length*2+10, wenn Ihr Container max_length==0 erlaubt
    for (size_t i {length-1}; i>=current; --i)
        values[i+1]=values[i];
    values[current]=val;
    ++length;
    return Vector::iterator{values+current};
}