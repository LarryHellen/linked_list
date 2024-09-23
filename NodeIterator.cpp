//
// Created by Larry Hellen on 9/23/24.
//

#ifndef NODEITERATOR_CPP
#define NODEITERATOR_CPP

#include "NodeIterator.h"

template<typename T>
NodeIterator<T>::NodeIterator(Node<T>* node) : current(node) {}

template<typename T>
NodeIterator<T> & NodeIterator<T>::operator++()
{
    current = current->next;
    return *this;
}

template<typename T>
NodeIterator<T>  NodeIterator<T>::operator++(int)
{
    NodeIterator<T> hold(current);
    current = current->next;
    return hold;
}

template<typename T>
NodeIterator<T> & NodeIterator<T>::operator--()
{
    current = current->prev;
    return *this;
}

template<typename T>
NodeIterator<T>  NodeIterator<T>::operator--(int)
{
    NodeIterator<T> hold(current);
    current = current->prev;
    return hold;
}

template<typename T>
T & NodeIterator<T>::operator*()
{
    return current->data;
}

template <typename U>
bool operator==(const NodeIterator<U>& iterator1, const NodeIterator<U>& iterator2)
{
    return iterator1.current == iterator2.current;
}

template <typename U>
bool operator!=(const NodeIterator<U>& iterator1, const NodeIterator<U>& iterator2)
{
    return iterator1.current != iterator2.current;;
}

#endif
