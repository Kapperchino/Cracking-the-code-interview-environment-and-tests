template <class T>
minStack<T>::minStack()
{
    index = -1;
    min = std::numeric_limits<int>::max();
    minStack = new minStack<T>();
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
    if (item < minStack->peek())
    {
        minStack->push(item);
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
    if (item == minStack->peek())
    {
        minStack->pop();
    }
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
    return minStack->peek();
}
