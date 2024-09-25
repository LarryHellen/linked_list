#include <iostream>
#include "LinkedList.h"
int main()
{
    LinkedList<int> l = {1, 2, 3};

    LinkedList<int> l2 = {4, 5, 6};

    std::cout << l << std::endl;
    std::cout << l2 << std::endl;

    l += l2;

    std::cout << l << std::endl;
    std::cout << l2 << std::endl;

    NodeIterator<int> it = l.begin();

    std::cout << *it << std::endl;
    it += 2;
    std::cout << *it << std::endl;
    it--;
    std::cout << *it << std::endl;




    return 0;
}
