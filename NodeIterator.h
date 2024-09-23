//
// Created by Larry Hellen on 9/23/24.
//

#ifndef NODEITERATOR_H
#define NODEITERATOR_H

#include "Node.h"
#include <iterator>

//all operators:
//increment postfix and prefix
//decrement postfix and prefix
//dereference
//equal and not equal


template <typename T>
class NodeIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
    Node<T>* current;

public:
    NodeIterator(Node<T>* node = nullptr);

    NodeIterator<T>& operator++(); //prefix ++it;
    NodeIterator<T> operator++(int); //postfix it++;

    NodeIterator<T>& operator--();
    NodeIterator<T> operator--(int);

    T& operator*();

    template <typename U>
    friend bool operator==(const NodeIterator<U>& iterator1, const NodeIterator<U>& iterator2);

    template <typename U>
    friend bool operator!=(const NodeIterator<U>& iterator1, const NodeIterator<U>& iterator2);
};


#include "NodeIterator.cpp"
#endif //NODEITERATOR_H
