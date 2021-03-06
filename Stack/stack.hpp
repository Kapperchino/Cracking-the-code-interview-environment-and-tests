#pragma once
#include <limits>
#include <stack>
#include <vector>
#include <cmath>
#define DEFAULT_SIZE 99
template <class T>
struct stackTriple
{
private:

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

template <class T>
struct queueStack
{
private:

public:
    queueStack();
    void add(T item);
    T get();
    T peek();
    bool isEmpty();
};

#include "queueStack.tcc"

void sortStack(std::stack<int> &stack);
