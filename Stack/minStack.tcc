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


