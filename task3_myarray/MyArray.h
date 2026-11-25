#ifndef MYARRAY_H
#define MYARRAY_H

class MyArray {
private:
    int* p;
    int N;

public:
    MyArray();
    MyArray(int n, int value = 0);
    MyArray(const MyArray& other);
    MyArray& operator=(const MyArray& other);
    ~MyArray();

    int size();
    int get(int index);
    void set(int index, int value);
    void display();

    MyArray merge(const MyArray& other);
    MyArray add(const MyArray& other);
    MyArray subtract(const MyArray& other);
    MyArray multiply(const MyArray& other);
    MyArray divide(const MyArray& other);
};

#endif
