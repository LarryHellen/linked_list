//
// Created by Larry Hellen on 9/24/24.
//

#include "ConstIterator.h"

template<typename T>
const T & ConstIterator<T>::operator*()
{
    return *current;
}
