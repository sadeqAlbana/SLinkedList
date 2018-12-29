#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    LinkedList<int> list;

    list.append(1);
    list.append(2);
    list.append(19);


    std::cout << list;

    std::cout <<list.at(4) <<std::endl;
    return 0;
}
