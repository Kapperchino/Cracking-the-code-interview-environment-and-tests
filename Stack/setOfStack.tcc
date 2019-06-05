template <class T>
setStack<T>::setStack()
{
    data.push_back(std::stack<T>());
    this->index = -1;
    this->maxStackSize = 10;
}

template <class T>
setStack<T>::setStack(int maxStackSize)
{
    this->index = -1;
    this->maxStackSize = maxStackSize;
}

template <class T>
void setStack<T>::push(T item)
{
    if (index >= data.size() * maxStackSize - 1)
    {
        data.push_back(std::stack<T>());
    }
    index++;
    data[data.size() - 1].push(item);
}

template <class T>
T setStack<T>::pop()
{
    item = data[data.size() - 1].pop();
    if (index > 0 && index % maxStackSize == 0)
    {
        data.pop_back();
    }
    index--;
    return item;
}

template <class T>
static T shiftStack(int index, bool isTop)
{
    std::stack curStack = data[index];
    T removeItem;
    if (isTop)
    {
        removeItem = curStack.pop();
    }
    else
    {
        std::stack<T> temp;
        T tempItem;
        //gets rid of the last element
        for (int x = 0; x < stack.size(); x++)
        {
            temp.push(curStack.pop());
        }
        removeItem = temp.pop();
        for (int x = 0; x < temp.size(); x++)
        {
            curStack.push(temp.pop());
        }
    }
    if (curStack.empty())
    {
        data.erase(data.begin(), data.begin() + index);
    }
    else if (stackIndex < data.size() - 1)
    {
        int pElem = shiftStack(index + 1, false);
        curStack.push(pElem);
    }
    return removeItem;
}

template <class T>
T setStack<T>::popAt(int index)
{
    return shiftStack(index, true);
}
