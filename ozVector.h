#pragma once
#ifndef OZVECTOR_H

#define OZVECTOR_H
#include <iostream>

using namespace std;

template <class T>
class ozVector
{
private:
    T *vector;
    int cap;
    int elem;

public:
    typedef T *Iterator;
    // constructor and big four
    ozVector(int maxCAP);
    ozVector(T *arr, int n);
    ~ozVector();
    ozVector(const ozVector &vec);
    ozVector<T> &operator=(const ozVector &trns);
    ozVector<T> &operator=(const ozVector &&trns);

    // Access operation
    T &operator[](int index);

    // Modifying operations
    void push_back(T item);
    T pop_back();
    void erase(Iterator first, Iterator second);
    void erase(Iterator itr);
    void clear();
    void insert(Iterator itr, T item);

    // Iterator
    Iterator begin() { return &vector[0]; }
    Iterator end() { return &vector[elem]; }

    // comparison
    bool operator==(ozVector<T> &vTEST);
    bool operator<(ozVector<T> &vTEST);

    // capacity
    int size() const;
    int capacity();
    int resize();
    bool empty();

    // friends
    friend ostream &operator<<(ostream &out, ozVector<T> &v)
    {
        out << '[';
        for (int i = 0; (int)i < v.size() - 1; i++)
        {
            out << v[i] << ", ";
        }
        out << v[v.size() - 1];
        out << ']';
        return out;
    }
};

#endif
