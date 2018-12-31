#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    LinkedList<int> list;

    list.append(11);

    list.append(22);
    list.append(19);
    list.insert(1,9994);
    //list.append(25);
    //list.append(66);

    std::cout << list;


    //list.remove(3);
    //std::cout << list;


    return 0;
}
