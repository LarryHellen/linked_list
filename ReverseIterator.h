//
// Created by Larry Hellen on 9/23/24.
//

#ifndef REVERSEITERATOR_H
#define REVERSEITERATOR_H
#include "Node.h"
#include "NodeIterator.h"

template <typename T>
class ReverseIterator : public NodeIterator<T>
{
    using NodeIterator<T>::current;
public:
    NodeIterator<T>& operator++(); //prefix ++it;
    NodeIterator<T> operator++(int); //postfix it++;

    NodeIterator<T>& operator--();
    NodeIterator<T> operator--(int);
};



#endif //REVERSEITERATOR_H
