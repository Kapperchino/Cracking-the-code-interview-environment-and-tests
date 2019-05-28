#include "linkList.hpp"
#include <unordered_set>

void removeDups(Node<int> *head)
{
    std::unordered_set<int> set;
    Node<int>* temp = head;
    Node<int>* prev = nullptr;
    while(temp)
    {
        if(set.find(temp->data)!=set.end())
        {
            prev->next = temp->next;
            delete temp;
        }
        else
        {
            set.insert(temp->data);
            prev = temp;
        }
        temp = temp->next;
    }
}