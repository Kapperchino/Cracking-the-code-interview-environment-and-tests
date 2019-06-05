#pragma once
#include <limits>
#define DEFAULT_SIZE 99
template <class T>
struct stackTriple
{
private:
    T *data = nullptr;
    int indecies[3];
    int size = 0;

public:
    stackTriple(int size);
    stackTriple();
    ~stackTriple();
    void push(T item, int index);
    T pop(int index);
    T peek(int index);
};

#include "tripleStack.tcc"

template <class T>
struct minStack
{
private:
    T data[1000];
    int index = 0;
    minStack<T>* minStack;
public:
    minStack();
    ~minStack();
    void push(T item);
    T pop();
    T peek();
    T getMin();
};

#include "minStack.tcc"
