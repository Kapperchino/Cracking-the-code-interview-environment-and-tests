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
int returnKToLast(Node<int> *head, int k);
void deleteMiddleNode(Node<int> *head);
void listPatition(Node<int>* head, int patrition);
int sumList(Node<int>* head1,Node<int>* head2);
bool checkPalindrome(Node<int>* head1);
Node<int>* checkIntersection(Node<int>* head1, Node<int>* head2);
bool isCircular(Node<int>* head);

#include "linkList.tcc"