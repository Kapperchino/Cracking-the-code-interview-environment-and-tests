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
    std::stack<T> stackMin;

public:
    minStack();
    void push(T item);
    T pop();
    T peek();
    T getMin();
};

#include "minStack.tcc"

template <class T>
struct setStack
{
private:
    std::vector<std::stack<T>> data;
    int index = 0;
    int maxStackSize = 0;
    T shiftStack(int index, bool isTop);

public:
    setStack();
    setStack(int maxStackSize);
    void push(T item);
    T pop();
    T peek();
    T popAt(int index);
    bool isEmpty();
};

#include "setOfStack.tcc"
