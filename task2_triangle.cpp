#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Triangle {
private:
    double a;
    double b;
    double c;

public:
    Triangle(double a = 1, double b = 1, double c = 1)
        : a(a), b(b), c(c) {
    }

    void Init(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    bool isTriangle() {
        if (a <= 0 || b <= 0 || c <= 0) {
            return false;
        }
        return a + b > c && a + c > b && b + c > a;
    }

    double getSideA() { return a; }
    double getSideB() { return b; }
    double getSideC() { return c; }

    void setSideA(double x) {
        if (x > 0) {
            a = x;
        } else {
            cout << "Error: side must be positive" << endl;
        }
    }

    void setSideB(double x) {
        if (x > 0) {
            b = x;
        } else {
            cout << "Error: side must be positive" << endl;
        }
    }

    void setSideC(double x) {
        if (x > 0) {
            c = x;
        } else {
            cout << "Error: side must be positive" << endl;
        }
    }

    double perimeter() {
        return a + b + c;
    }

    double area() {
        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return 0;
        }
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    int typeTriangle() {
        if (!isTriangle()) {
            return 0;
        }

        double x = a;
        double y = b;
        double z = c;
        if (x > z) {
            swap(x, z);
        }
        if (y > z) {
            swap(y, z);
        }

        double left = x * x + y * y;
        double right = z * z;

        if (fabs(left - right) < 1e-6) {
            return 1;
        }
        if (left > right) {
            return 2;
        }
        return 3;
    }

    void display() {
        cout << fixed << setprecision(2);
        cout << "Sides: " << a << ' ' << b << ' ' << c << endl;

        if (!isTriangle()) {
            cout << "Error: cannot form a triangle" << endl;
            return;
        }

        cout << "Perimeter: " << perimeter() << endl;
        cout << "Area: " << area() << endl;

        int type = typeTriangle();
        if (type == 1) {
            cout << "Type: 直角三角形" << endl;
        } else if (type == 2) {
            cout << "Type: 锐角三角形" << endl;
        } else if (type == 3) {
            cout << "Type: 钝角三角形" << endl;
        }
    }
};

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    Triangle t(a, b, c);
    t.display();

    return 0;
}
