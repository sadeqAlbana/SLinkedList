#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
    LinkedList<int> list;

    list.append(1);

    list << 2;

    list << 3 << 4 << 5 << 2323 << 4334;

    list.insert(2,55);
    list << 44;

    list.remove(4);

    list.append(2);

    list.removeLast();
    list.removefirst();

    list[3]=599;
    list.at(2)=444;

    cout <<list;


    return 0;
}
