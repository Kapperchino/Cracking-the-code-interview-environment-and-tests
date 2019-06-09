template <class T>
minStack<T>::minStack()
{
    this->index = -1;
    stackMin.push(std::numeric_limits<T>::max());
}

template <class T>
void minStack<T>::push(T item)
{
    if (index >= 1000)
    {
        return;
    }
    index++;
    data[index] = item;
    if (item < stackMin.top())
    {
        stackMin.push(item);
    }
}

template <class T>
T minStack<T>::pop()
{
    if (index <= -1)
    {
        return T();
    }

    T item = data[index];
    index--;
    if (item == stackMin.top())
    {
        stackMin.pop();
    }
    return item;
}

template <class T>
T minStack<T>::peek()
{
    if (index <= -1)
    {
        return T();
    }

    T item = data[index];
    return item;
}

template <class T>
T minStack<T>::getMin()
{
    return stackMin.top();
}
