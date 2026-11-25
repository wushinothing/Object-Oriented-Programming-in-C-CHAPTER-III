#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Point {
private:
    double x;
    double y;
    double z;

public:
    Point(double x = 0, double y = 0, double z = 0)
        : x(x), y(y), z(z) {
    }

    void Init(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    void display() {
        cout << fixed << setprecision(2)
             << "(" << x << ", " << y << ", " << z << ")";
    }

    double distanceTo(const Point& other) {
        double dx = this->x - other.x;
        double dy = this->y - other.y;
        double dz = this->z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    friend double euclideanDistance(const Point& a, const Point& b);
    friend double manhattanDistance(const Point& a, const Point& b);
    friend double chebyshevDistance(const Point& a, const Point& b);
    friend Point midpoint(const Point& a, const Point& b);
};

double euclideanDistance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double manhattanDistance(const Point& a, const Point& b) {
    double dx = fabs(a.x - b.x);
    double dy = fabs(a.y - b.y);
    double dz = fabs(a.z - b.z);
    return dx + dy + dz;
}

double chebyshevDistance(const Point& a, const Point& b) {
    double dx = fabs(a.x - b.x);
    double dy = fabs(a.y - b.y);
    double dz = fabs(a.z - b.z);
    return max(dx, max(dy, dz));
}

Point midpoint(const Point& a, const Point& b) {
    return Point((a.x + b.x) / 2.0,
                 (a.y + b.y) / 2.0,
                 (a.z + b.z) / 2.0);
}

int main() {
    double x1, y1, z1;
    double x2, y2, z2;

    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;

    Point A(x1, y1, z1);
    Point B(x2, y2, z2);

    cout << fixed << setprecision(2);
    cout << "A = ";
    A.display();
    cout << endl;

    cout << "B = ";
    B.display();
    cout << endl;

    cout << "Euclidean distance: " << euclideanDistance(A, B) << endl;
    cout << "Manhattan distance: " << manhattanDistance(A, B) << endl;
    cout << "Chebyshev distance: " << chebyshevDistance(A, B) << endl;

    Point center = midpoint(A, B);
    cout << "Midpoint: ";
    center.display();
    cout << endl;

    return 0;
}
