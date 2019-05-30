#include "linkList.hpp"
#include <unordered_set>

void removeDups(Node<int> *head)
{
    std::unordered_set<int> set;
    Node<int> *temp = head;
    Node<int> *prev = nullptr;
    Node<int> *delTemp = nullptr;
    while (temp)
    {
        if (set.find(temp->data) != set.end())
        {
            prev->next = temp->next;
            delTemp = temp;
            temp = temp->next;
            delete delTemp;
        }
        else
        {
            set.insert(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }
}

void removeDupsNoBuf(Node<int> *head)
{
    Node<int> *iter1 = head;
    Node<int> *iter2 = nullptr;
    Node<int> *prev = nullptr;
    Node<int> *delTemp = nullptr;

    while (iter1)
    {
        iter2 = iter1->next;
        prev = iter1;
        while (iter2)
        {
            if (iter1->data == iter2->data)
            {
                prev->next = iter2->next;
                delTemp = iter2;
                iter2 = iter2->next;
                delete delTemp;
            }
            else
            {
                prev = iter2;
                iter2 = iter2->next;
            }
        }
        iter1 = iter1->next;
    }
}

int returnKToLast(Node<int> *head, int k)
{
    Node<int> *iter = head;
    Node<int> *kIter = iter;
    int count = 0;

    while (kIter)
    {
        if (count > k - 1)
        {
            kIter = kIter->next;
            iter = iter->next;
        }
        else
        {
            kIter = kIter->next;
            count++;
        }
    }
    return iter->data;
}

void deleteMiddleNode(Node<int> *head)
{
    Node<int> *slow = head;
    Node<int> *fast = head;
    Node<int> *prev = nullptr;
    Node<int> *delTemp = nullptr;
    while (fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = slow->next->next;
    }
    delTemp = slow;
    prev->next = slow->next;
    delete delTemp;
}

void listPatition(Node<int> *head, int patrition)
{
    //make another list with numbers less than patrition,
    //then combine them together
    Node<int> *iter = head;
    Node<int> *patritionPos = nullptr;
    Node<int> *smallListPtr = nullptr;
    Node<int> *smallListIter = nullptr;
    Node<int> *prev = nullptr;
    while (iter)
    {
        if (iter->data == patrition && !patritionPos)
        {
            patritionPos = iter;
        }

        if (iter->data < patrition)
        {
            //removes the node
            smallListPtr = iter;
            if (prev)
            {
                prev->next = iter->next;
            }
            iter = iter->next;
            smallListPtr->next = nullptr;
            //first element in small list
            if (!smallListIter)
            {
                head = smallListPtr;
                smallListIter = smallListPtr;
            }
            else
            {
                smallListIter->next = smallListPtr;
                smallListIter = smallListPtr;
            }
        }
        else
        {
            prev = iter;
            iter = iter->next;
        }
    }
    //done with the making of a new list
    smallListIter->next = patritionPos;
}
