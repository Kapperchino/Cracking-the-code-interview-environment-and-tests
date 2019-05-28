
//Linked list implementation start
template <class T>
Node<T>::Node()
{
    this->data = T();
    this->next = nullptr;
}

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
}

template <class T>
LinkedList<T>::LinkedList()
{
    this->head = new Node<T>();
}

template <class T>
LinkedList<T>::LinkedList(std::vector<T> input)
{
    if (input.size() > 0)
    {
        for (int x = 0; x < input.size(); x++)
        {
            this->insertBack(input[x]);
        }
    }
    else
    {
        this->head = new Node<T>();
    }
}

template <class T>
void LinkedList<T>::insertBack(T value)
{
    Node<T> *temp = this->head;
    Node<T> *newNode = new Node<T>(value);
    if (!temp)
    {
        temp = newNode;
        return;
    }

    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp = head;
    Node<T>* oldTemp = nullptr;
    while (temp)
    {
        temp = temp->next;
        delete head;
        head = temp;
    }
}

template <class T>
std::ostream &operator<<(std::ostream &outputStream, const LinkedList<T> &list)
{
    Node<T> *temp = list.head;
    std::string output;
    if (temp)
    {
        while (temp)
        {
            output += std::to_string(temp->data);
            output += ",";
            temp = temp->next;
        }
    }
    return outputStream << output;
}

template <class T>
bool operator==(const LinkedList<T> &a, const LinkedList<T> &b)
{
    Node<T> *temp = a.head;
    Node<T> *temp1 = b.head;
    while (temp && temp1)
    {
        if (temp->data != temp1->data)
        {
            return false;
        }
        temp1 = temp1->next;
        temp = temp->next;
    }
    return true;
}

//Linked list implementation end