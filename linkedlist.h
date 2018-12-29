#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <assert.h>
template<class T>
struct Node
{
    Node(){}
    Node(T Data){data=Data;}
    Node<T> *next=nullptr;
    Node<T> *prev=nullptr;
    T data;
};


template<class T>
class LinkedList
{
public:
    LinkedList();

    Node<T> *allocNode(T data);
    void append(T data);
    T at(int pos);
    int size(){return _size;}
    template<class C>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<C> &list);

private:
    inline void incSize(){++_size;}
    Node<T> *first=nullptr;
    int _size=0;
};



template <class T>
LinkedList<T>::LinkedList()
{

}

template <class T>
Node<T> *LinkedList<T>::allocNode(T data)
{
    incSize();
    return new Node<T>(data);
}

template<class T>
void LinkedList<T>::append(T data)
{
    auto newNode=allocNode(data);
    if(!first)
    {
        first=newNode;
    }
    else
    {
        auto *tmp=first;

        while (tmp->next)
            tmp=tmp->next;

        tmp->next=newNode;
    }
}
template<class T>
T LinkedList<T>::at(int pos)
{
    assert(pos<size());

    auto tmp=first;
    for(int i=0; i<pos; i++)
    {
        tmp=tmp->next;
    }

    return tmp->data;
}
template<class C>
std::ostream& operator<< (std::ostream& os, const LinkedList<C> &list) {

    Node<int> *node=list.first;
    do
    {
        os <<"data: "<<node->data << std::endl;
        node=node->next;
    }
    while (node);

    return os;
}


#endif // LINKEDLIST_H
