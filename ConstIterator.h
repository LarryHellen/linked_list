//
// Created by Larry Hellen on 9/24/24.
//

#ifndef CONSTITERATOR_H
#define CONSTITERATOR_H
#include "NodeIterator.h"

template <typename T>
class ConstIterator : public NodeIterator<T>
{
private:
    using NodeIterator<T>::current;
public:
    const T& operator*();
};



#endif //CONSTITERATOR_H
