#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include "LinkedList.h"
template<typename T>
LinkedList<T>::LinkedList()
{

}

template<typename T>
LinkedList<T>::LinkedList(const std::initializer_list<T> &list)
{
    T* walker = list.begin();
    while(walker != nullptr)
    {
        push_back({*walker});
        ++walker;
    }
}

//TODO
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{

}

//TODO
template<typename T>
LinkedList<T>::~LinkedList()
{

}

template<typename T>
Node<T>* LinkedList<T>::create_node(const T& data)
{
    Node<T>* n = new Node<T>;
    n->data = data;

    return n;
}


template<typename T>
void LinkedList<T>::add_first_node(const T& data)
{
    Node<T> n = create_node(data);
    head = n;
    tail = n;
}

template<typename T>
void LinkedList<T>::push_front(Node<T> *node)
{

}

template<typename T>
void LinkedList<T>::push_back(Node<T> *node)
{

}

template<typename T>
void LinkedList<T>::one_node_pop()
{

}

template<typename T>
void LinkedList<T>::remove(Node<T> *target)
{

}

template<typename T>
void LinkedList<T>::insert_before(Node<T> *target, Node<T> *data)
{

}

template<typename T>
Node<T> *LinkedList<T>::search(const T &target)
{
    return nullptr;
}



template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
    return *this;
}

template<typename T>
int LinkedList<T>::size() const
{
    return 0;
}

template<typename T>
void LinkedList<T>::push_front(const T &data)
{
    push_front(createNode(data));
}

template<typename T>
void LinkedList<T>::push_back(const T &data)
{

}

template<typename T>
void LinkedList<T>::pop_front()
{

}

template<typename T>
void LinkedList<T>::pop_back()
{

}

template<typename T>
T &LinkedList<T>::front()
{
    return T();
}

template<typename T>
T &LinkedList<T>::back()
{
    return T();
}

template<typename T>
const T &LinkedList<T>::front() const
{
    return T();
}

template<typename T>
const T &LinkedList<T>::back() const
{
    return T();
}

template<typename T>
bool LinkedList<T>::empty() const
{
    return false;
}

template<typename T>
bool LinkedList<T>::contains(const T &data)
{
    return false;
}

template<typename T>
void LinkedList<T>::remove(const T &data)
{

}

template<typename T>
void LinkedList<T>::insert_before(const T &targetData, const T &newData)
{

}

template<typename T>
void LinkedList<T>::insert_after(const T &targetData, const T &newData)
{

}

template<typename U>
LinkedList<U> operator+(const LinkedList<U> &list1, const LinkedList<U> &list2)
{
    return LinkedList<U>();
}

template<typename T>
Node<T> *LinkedList<T>::createNode(const T &data)
{
    return nullptr;
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const LinkedList<T> &list)
{
    Node<T>* walker = list.head;
    
    while(walker)
    {
        out << walker->data << " ";
        walker = walker->next;
    }
    return out;
}

#endif