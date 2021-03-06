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
    if (!head)
    {
        return;
    }
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

int sumList(Node<int> *head1, Node<int> *head2)
{
    if (!head1 && !head2)
    {
        return 0;
    }

    Node<int> *iter1 = head1;
    Node<int> *iter2 = head2;
    int multiplyer = 1;
    int carryOver = 0;
    int result = 0;
    int temp = 0;
    while (iter1 || iter2)
    {
        if (iter1)
        {
            temp += iter1->data;
        }
        if (iter2)
        {
            temp += iter2->data;
        }
        //after getting the amount to add

        result = result + (temp % 10 + carryOver) * multiplyer;
        if (temp >= 10)
        {
            carryOver = 1;
        }
        else
        {
            carryOver = 0;
        }

        iter1 = iter1->next;
        iter2 = iter2->next;
        temp = 0;
        multiplyer *= 10;
    }
    return result;
}

bool checkPalindrome(Node<int> *head)
{
    Node<int> *slow = head;
    Node<int> *fast = head;
    Node<int> *prev = nullptr;
    Node<int> *next = nullptr;
    Node<int> *cur = nullptr;
    //gets the middle Node
    while (fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = slow->next->next;
    }
    //sepereates the two lists
    prev->next = nullptr;
    cur = slow;
    next = cur->next;
    //reverses the second half of the list
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    slow = head;
    cur = prev;

    //checks both sides
    while (slow && cur)
    {
        if (slow->data != cur->data)
        {
            return false;
        }
        slow = slow->next;
        cur = cur->next;
    }
    return true;
}

Node<int> *checkIntersection(Node<int> *head1, Node<int> *head2)
{
    Node<int> *temp1 = head1;
    Node<int> *temp2 = head2;
    std::unordered_set<Node<int> *> set1;

    while (temp1 || temp2)
    {
        if (temp1)
        {
            auto item = set1.insert(temp1);
            if (!item.second)
            {
                return temp1;
            }
        }

        if (temp2)
        {
            auto item = set1.insert(temp2);
            if (!item.second)
            {
                return temp2;
            }
        }
        if (temp1)
        {
            temp1 = temp1->next;
        }
        else
        {
            temp1 = nullptr;
        }

        if (temp2)
        {
            temp2 = temp2->next;
        }
        else
        {
            temp2 = nullptr;
        }
    }

    return nullptr;
}

bool isCircular(Node<int> *head)
{
    if (!head || !head->next)
    {
        return false;
    }

    Node<int> *slow = head;
    Node<int> *fast = head->next;

    while (fast && fast->next)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
