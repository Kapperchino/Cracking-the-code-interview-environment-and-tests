#pragma once
#include <vector>
#include <iostream>
#include <string>

template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T>();
    Node<T>(T data);
};

template <class T>
struct LinkedList
{
    Node<T> *head;
    LinkedList<T>();
    LinkedList<T>(std::vector<T> data);
    void insertBack(T value);
    template <class U>
    friend bool operator==(const LinkedList<U> &a, const LinkedList<U> &b);
    template <class U>
    friend std::ostream &operator<<(std::ostream &outputStream, const LinkedList<U> &list);
    ~LinkedList();
};

void removeDups(Node<int> *head);
void removeDupsNoBuf(Node<int> *head);

#include "linkList.tcc"