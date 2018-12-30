#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <assert.h>
template<class T>
struct Node
{
    Node(){}
    ~Node()
    {
        //delete data;
    }
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
    Node<T> *allocNode(const T &value);
    void append(const T &value);
    const T &at(const int &pos) const;
    void insert(const int &before, const T &value);
    void replace(const int &index, const T &value);
    void remove(const int &index);
    void removeLast();
    void removeFirst();
    int size() const {return _size;}
    template<class C>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<C> &list);

private:
    inline void incSize(){++_size;}
    inline void decSize(){--_size;}
    void removeNode(Node<T> * node);
    Node<T> *first=nullptr;
    int _size=0;
};



template <class T>
LinkedList<T>::LinkedList()
{

}

template <class T>
Node<T> *LinkedList<T>::allocNode(const T &value)
{
    incSize();
    return new Node<T>(value);
}

template<class T>
void LinkedList<T>::append(const T &value)
{
    auto newNode=allocNode(value);
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
        newNode->prev=tmp;
    }
}
template<class T>
const T& LinkedList<T>::at(const int &pos) const
{
    assert(pos<size());

    auto tmp=first;
    for(int i=0; i<pos; i++)
    {
        tmp=tmp->next;
    }

    return tmp->data;
}

template<class T>
void LinkedList<T>::insert(const int &before,const T &value)
{
    assert(before<size());

    auto newNode=allocNode(value);

    auto tmp=first;

    for(int i=0; i<before; i++)
        tmp=tmp->next;


    if(tmp->prev) //if tmp->prev is not empty then prev is not the first node
        tmp->prev->next=newNode;
    else
        first=newNode;

    newNode->next=tmp;
    newNode->prev=tmp->prev;
    tmp->prev=newNode;
}

template<class T>
void LinkedList<T>::replace(const int &index, const T &value)
{
    assert(index<size());

    auto tmp=first;

    for(int i=0; i<index; i++)
        tmp=tmp->next;

    tmp->data=value;

}

template<class T>
void LinkedList<T>::remove(const int &index)
{
    assert(index<size());
    auto tmp=first;

    for(int i=0; i<index; i++)
        tmp=tmp->next;

    removeNode(tmp);
}

template<class T>
void LinkedList<T>::removeLast()
{
    assert(size());

    auto tmp=first;
    while (tmp->next)
    {
        tmp=tmp->next;
    }

    removeNode(tmp);
}

template<class T>
void LinkedList<T>::removeFirst()
{
    assert(size());
    removeNode(first);
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    decSize();

    if(node->prev)
        node->prev->next=node->next;

    if(node->next)
        node->next->prev=node->prev;

    if(node==first)
    {
        if(size())
            first=node->next;
        else
            first=nullptr;
    }

    delete node;

}
template<class C>
std::ostream& operator<< (std::ostream& os, const LinkedList<C> &list)
{
    auto *node=list.first;

    os << "LinkedList: { ";
    if(node){
        do
        {
            os<<node->data << ",";
            node=node->next;
        }
        while (node);
    }
    os << "\b }" << std::endl;
    return os;
}


#endif // LINKEDLIST_H
