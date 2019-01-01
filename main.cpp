#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    LinkedList<int> list;

    //list.append(11);
    //list.append(22);

    list << 1 << 2 << 55 << 4;
    std::cout << list;

    cout << list[2];


    return 0;
}
