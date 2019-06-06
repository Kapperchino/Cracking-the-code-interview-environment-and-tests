#include "stack.hpp"
//uses one stack
void sortStack(std::stack<int> &stack)
{
    std::stack<int> tempStack;
    int temp = 0;
    while (!stack.empty())
    {
        temp = stack.top();
        stack.pop();
        while (!tempStack.empty() && tempStack.top() > temp)
        {
            stack.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }

    while (!tempStack.empty())
    {
        stack.push(tempStack.top());
        tempStack.pop();
    }
}