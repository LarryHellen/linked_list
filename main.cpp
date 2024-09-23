#include <iostream>
#include "LinkedList.h"
int main()
{
    LinkedList<int> l;

    LinkedList<int>::iterator iter = l.begin();

    for(auto& i : l)
        std::cout << i;

    return 0;
}
