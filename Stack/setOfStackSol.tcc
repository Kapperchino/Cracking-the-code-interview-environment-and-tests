template <class T>
setStack<T>::setStack()
{
    this->data.push_back(std::stack<T>());
    this->index = -1;
    this->maxStackSize = 10;
}

template <class T>
setStack<T>::setStack(int maxStackSize)
{
    this->data.push_back(std::stack<T>());
    this->index = -1;
    this->maxStackSize = maxStackSize;
}

template <class T>
void setStack<T>::push(T item)
{
    if (std::abs(index) >= (data.size() * maxStackSize - 1))
    {
        data.push_back(std::stack<T>());
    }
    index++;
    data[data.size() - 1].push(item);
}

template <class T>
T setStack<T>::pop()
{
    T item = data[data.size() - 1].top();
    data[data.size() - 1].pop();
    if (index > 0 && index % maxStackSize == 0)
    {
        data.pop_back();
    }
    index--;
    return item;
}

template <class T>
T setStack<T>::shiftStack(int index, bool isTop)
{
    std::stack<T> &curStack = data[index];
    T removeItem;
    if (isTop)
    {
        removeItem = curStack.top();
        curStack.pop();
    }
    else
    {
        std::stack<T> temp;
        T tempItem;
        //gets rid of the last element
        while (!curStack.empty())
        {
            temp.push(curStack.top());
            curStack.pop();
        }
        removeItem = temp.top();
        temp.pop();
        while (!temp.empty())
        {
            curStack.push(temp.top());
            temp.pop();
        }
    }
    if (curStack.empty())
    {
        data.erase(data.begin() + index);
    }
    else if (index < data.size() - 1)
    {
        int pElem = shiftStack(index + 1, false);
        curStack.push(pElem);
    }
    return removeItem;
}

template <class T>
T setStack<T>::popAt(int index)
{
    this->index--;
    return shiftStack(index, true);
}

template <class T>
bool setStack<T>::isEmpty()
{
    return index < 0;
}
