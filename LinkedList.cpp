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
    for (const T& element : list)
    {
        this->push_back(element);
    }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    copy_list(list);
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear_list();
}

template<typename T>
void LinkedList<T>::copy_list(Node<T> &list)
{
    if(list.empty())
        return;

    Node<T>* walker = list.head;

    while(walker != nullptr)
    {
        push_back(walker->data);
        walker = walker->next;
    }
}

template<typename T>
void LinkedList<T>::clear_list()
{
    while(head != nullptr)
        pop_back();
}


template<typename T>
Node<T>* LinkedList<T>::create_node(const T& data)
{
    Node<T>* n = new Node<T>;
    n->data = data;

    return n;
}

template<typename T>
void LinkedList<T>::add_first_node(Node<T>* node)
{
    head = node;
    tail = node;

    _size++;
}

template<typename T>
void LinkedList<T>::push_front(Node<T> *node)
{
    if(empty())
    {
        add_first_node(node);
        return;
    }

    node->next = head;
    head->prev = node;
    head = node;
    _size++;
}

template<typename T>
void LinkedList<T>::push_back(Node<T> *node)
{
    if(empty())
    {
        add_first_node(node);
        return;
    }

    node->prev = tail;
    tail->next = node;
    tail = node;
    _size++;
}

template<typename T>
void LinkedList<T>::one_node_pop()
{
    delete[] head;
    head = nullptr;
    tail = nullptr;
    _size--;
}

template<typename T>
void LinkedList<T>::remove(Node<T> *target)
{
    if(target == nullptr)
        return;

    if(target == head)
    {
        pop_front();
        return;
    }

    if(target == tail)
    {
        pop_back();
        return;
    }

    Node<T>* p = target->prev;
    Node<T>* n = target->next;

    p->next = n;
    n->prev = p;

    delete target;
    _size--;
}

template<typename T>
void LinkedList<T>::insert_before(Node<T> *target, Node<T> *data)
{
    if(empty())
    {
        add_first_node(data);
        return;
    }

    if(target == head)
    {
        push_front(data);
        return;
    }

    if(target == nullptr)
    {
        push_back(data);
        return;
    }

    data->next = target;
    data->prev = target->prev;

    target->prev->next = data;
    target->prev = data;

    _size++;
}

template<typename T>
Node<T> *LinkedList<T>::search(const T &target)
{
    Node<T>* walker = head;
    while(walker != nullptr)
    {
        if(walker->data == target)
            return walker;
        walker = walker->next;
    }

    return nullptr;
}



template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list)
{
    if(this == list)
        return *this;

    clear_list();
    copy_list(list);

    return *this;
}

template<typename T>
int LinkedList<T>::size() const
{
    return _size;
}

template<typename T>
void LinkedList<T>::push_front(const T &data)
{
    push_front(create_node(data));
}

template<typename T>
void LinkedList<T>::push_back(const T &data)
{
    push_back(create_node(data));
}

template<typename T>
void LinkedList<T>::pop_front()
{
    if(head->next == nullptr)
    {
        one_node_pop();
        return;
    }

    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    _size--;
}

template<typename T>
void LinkedList<T>::pop_back()
{
    if(tail->prev == nullptr)
    {
        one_node_pop();
        return;
    }

    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    _size--;
}

template<typename T>
T &LinkedList<T>::front()
{
    return head->data;
}

template<typename T>
T &LinkedList<T>::back()
{
    return tail->data;
}

template<typename T>
const T &LinkedList<T>::front() const
{
    return head->data;
}

template<typename T>
const T &LinkedList<T>::back() const
{
    return tail->data;
}

template<typename T>
bool LinkedList<T>::empty() const
{
    return _size == 0;
}

template<typename T>
bool LinkedList<T>::contains(const T &data)
{
    return search(data);
}

template<typename T>
void LinkedList<T>::remove(const T &data)
{
    remove(search(data));
}

template<typename T>
void LinkedList<T>::insert_before(const T &targetData, const T &newData)
{
    Node<T>* target = search(targetData);
    if(target != nullptr)
        insert_before(target, create_node(newData));
}

template<typename T>
void LinkedList<T>::insert_after(const T &targetData, const T &newData)
{
    Node<T>* target = search(targetData);
    if(target != nullptr)
        insert_before(target->next, create_node(newData));
}

template<typename U>
LinkedList<U> operator+(const LinkedList<U> &list1, const LinkedList<U> &list2)
{
    LinkedList<U> ret(list1);

    Node<U>* walker = list2.head;
    while(walker != nullptr)
    {
        ret.push_back(walker->data);
        walker = walker->next;
    }

    return ret;
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

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin()
{
    return LinkedList<T>::iterator(head);
}

template<typename T>
typename LinkedList<T>::iterator LinkedList<T>::end()
{
    return LinkedList<T>::iterator(nullptr);
}

template<typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rbegin()
{
    return LinkedList<T>::iterator(tail);
}

template<typename T>
typename LinkedList<T>::reverse_iterator LinkedList<T>::rend()
{
    return LinkedList<T>::iterator(nullptr);
}

#endif
