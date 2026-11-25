#include "MyArray.h"

#include <iostream>
using namespace std;

int main() {
    int nA, nB;

    cout << "A size: ";
    if (!(cin >> nA) || nA <= 0) {
        cout << "A size must be a positive integer." << endl;
        return 1;
    }

    MyArray A(nA);
    cout << "A elements: ";
    for (int i = 0; i < nA; i++) {
        int value;
        cin >> value;
        A.set(i, value);
    }

    cout << "B size: ";
    if (!(cin >> nB) || nB <= 0) {
        cout << "B size must be a positive integer." << endl;
        return 1;
    }

    MyArray B(nB);
    cout << "B elements: ";
    for (int i = 0; i < nB; i++) {
        int value;
        cin >> value;
        B.set(i, value);
    }

    cout << "\nA = ";
    A.display();
    cout << "B = ";
    B.display();

    MyArray merged = A.merge(B);
    cout << "A merge B = ";
    merged.display();

    MyArray sum = A.add(B);
    cout << "A + B = ";
    sum.display();

    MyArray difference = A.subtract(B);
    cout << "A - B = ";
    difference.display();

    MyArray product = A.multiply(B);
    cout << "A * B = ";
    product.display();

    MyArray quotient = A.divide(B);
    cout << "A / B = ";
    quotient.display();

    // Silent deep-copy check: modifying copy must not change A.
    int originalFirst = A.get(0);
    MyArray copy = A;
    copy.set(0, 100);
    if (A.get(0) != originalFirst || copy.get(0) != 100) {
        cout << "Deep copy test failed" << endl;
    }

    return 0;
}
