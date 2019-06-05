template <class T>
stackTriple<T>::stackTriple(int size)
{
    data = new int[size];
    this->size = size;
    for (int x = 0; x < 3; x++)
    {
        this->indecies[x] = x * (size / 3);
    }
}

template <class T>
stackTriple<T>::stackTriple()
{
    size = DEFAULT_SIZE;
    data = new int[size];
    for (int x = 0; x < 3; x++)
    {
        this->indecies[x] = x * (size / 3);
    }
}

template <class T>
stackTriple<T>::~stackTriple()
{
    delete data;
}

template <class T>
void stackTriple<T>::push(T item, int index)
{
    if (index >= 3 || indecies[index] + 1 > this->size / 3 * (index+1))
    {
        return;
    }
    data[indecies[index]] = item;
    indecies[index]++;
}

template <class T>
T stackTriple<T>::pop(int index)
{
    if (index >= 3 || indecies[index] > this->size / 3 * (index+1))
    {
        return T();
    }
    indecies[index]--;
    T item = data[indecies[index]];
    return item;
}

template <class T>
T stackTriple<T>::peek(int index)
{
    if (index >= 3 || indecies[index] > this->size / 3 * (index+1))
    {
        return T();
    }
    T item = data[indecies[index] - 1];
    return item;
}
