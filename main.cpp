#include "vector.h"


using namespace std;

int main() {
    Vector v1{1,2,3} , v2;
    v2=v1;
    v1.print();
    v2.print();
    return 0;
}