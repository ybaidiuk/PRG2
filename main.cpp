#include "vector.h"


using namespace std;

int main() {
//max muss functionieren
//min
    //для мін максиму ітератор Басік  // інклид Алгоритм
    //von cpp to Header file
    // Merge
    // Template_test.cpp

    const Vector<double> v{1, 2, 2.5, 3, 5};

    for (double e : v) {
        cout<< e<< "    ";
    }


    // dann absiechenrung zumachen
//    Vector x;
//
////	Test der Absicherung
//    x.push_back(1);
//    auto e = x.end();
//    auto b = x.begin();
//
//    try {
//        cout << *e << endl;
//    } catch (runtime_error &e) {
//        cout << e.what() << endl;
//    }
//    cout << *b << endl;
//    x.pop_back();
//    try {
//        cout << *b << endl;
//    } catch (runtime_error &e) {
//        cout << e.what() << endl;
//    }
//
////	Text von Max
//    Vector y{5, 10, 8};
//    auto i = max_element(y.begin(), y.end());
//    cout << "Max: " << *i << endl;
//
//
////	Testen sie Min, Accumulate, count_if, ..., Sort
    return 0;
}

/*
Out of bounds
1
Out of bounds
Max: 10
*/