//
// Created by Larry Hellen on 9/23/24.
//

#include "ReverseIterator.h"

template<typename T>
NodeIterator<T> & ReverseIterator<T>::operator++()
{
    current = current->prev;
    return *this;
}

template<typename T>
NodeIterator<T> ReverseIterator<T>::operator++(int)
{
    NodeIterator<T> hold(current);
    current = current->prev;
    return hold;
}

template<typename T>
NodeIterator<T> & ReverseIterator<T>::operator--()
{
    current = current->next;
    return *this;
}

template<typename T>
NodeIterator<T> ReverseIterator<T>::operator--(int)
{
    NodeIterator<T> hold(current);
    current = current->next;
    return hold;
}
