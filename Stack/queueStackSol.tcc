template <class T>
queueStack<T>::queueStack()
{
}

template <class T>
void queueStack<T>::add(T item)
{
    this->data.push(item);
}

template <class T>
T queueStack<T>::get()
{
    std::stack<T> temp;
    while (!data.empty())
    {
        temp.push(data.top());
        data.pop();
    }
    T item = temp.top();
    temp.pop();
    while (!temp.empty())
    {
        data.push(temp.top());
        temp.pop();
    }
    return item;
}

template <class T>
T queueStack<T>::peek()
{
    std::stack<T> temp;
    while (!data.empty())
    {
        temp.push(data.top());
        data.pop();
    }
    T item = temp.top();
    while (!temp.empty())
    {
        data.push(temp.top());
        temp.pop();
    }
    return item;
}

template <class T>
bool queueStack<T>::isEmpty()
{
    return data.empty();
}
