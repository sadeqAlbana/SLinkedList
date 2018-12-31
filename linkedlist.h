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
    const T &at(const int &pos) const;
    T value(const int &pos) const;
    const T &first() const;
    const T &last() const;

    void append(const T &value);
    void insert(const int &before, const T &value);
    void replace(const int &pos, const T &value);
    void remove(const int &pos);
    void removeLast();
    void removefirst();
    int size() const {return _size;}
    int count() const {return size();}
    int length() const {return size();}
    bool isEmpty(){return size();}
    operator bool(){return isEmpty();}
    template<class C>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<C> &list);

private:
    Node<T> *allocNode(const T &value);
    inline void incSize(){++_size;}
    inline void decSize(){--_size;}
    void removeNode(Node<T> * node);
    Node<T> *getNode(const int &pos) const;
    Node<T> *getLastNode() const;
    Node<T> *_first=nullptr;
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
    if(!_first)
    {
        newNode->prev=newNode;
        newNode->next=newNode;
        _first=newNode;
    }
    else
    {
        auto *tmp=getLastNode();

        //std::cout << std::endl << (tmp==_first) << std::endl;

        _first->prev=newNode;
        newNode->next=_first;
        newNode->prev=tmp;
        tmp->next=newNode;
    }
}
template<class T>
const T& LinkedList<T>::at(const int &pos) const
{
    assert(pos<size());

    auto tmp=getNode(pos);

    return tmp->data;
}

template<class T>
const T &LinkedList<T>::first() const
{
    assert(size());
    return _first->data;
}

template<class T>
const T &LinkedList<T>::last() const
{
    return getLastNode()->data;
}

template<class T>
void LinkedList<T>::insert(const int &before,const T &value)
{
    assert(before<size());

    auto newNode=allocNode(value);

    auto tmp=getNode(before);


    if(tmp->next==_first)
    {
        newNode->prev=tmp;
        tmp->next=newNode;
        _first=newNode;
    }
    else
    {
        newNode->prev=tmp->prev;
        newNode->prev->next=newNode;
    }

    newNode->next=tmp;
    tmp->prev=newNode;


}

template<class T>
void LinkedList<T>::replace(const int &pos, const T &value)
{
    assert(pos<size());

    auto tmp=getNode(pos);
    tmp->data=value;

}

template<class T>
void LinkedList<T>::remove(const int &pos)
{
    assert(pos<size());

    removeNode(getNode(pos));
}

template<class T>
void LinkedList<T>::removeLast()
{
    assert(size());
    removeNode(getLastNode());
}

template<class T>
void LinkedList<T>::removefirst()
{
    assert(size());
    removeNode(_first);
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    decSize();

    if(node->prev)
        node->prev->next=node->next;

    if(node->next)
        node->next->prev=node->prev;

    if(node==_first)
    {
        if(size())
            _first=node->next;
        else
            _first=nullptr;
    }

    delete node;

}

template<class T>
Node<T> *LinkedList<T>::getNode(const int &pos) const
{
    auto tmp=_first;

    for(int i=0; i<pos; i++)
        tmp=tmp->next;

    return tmp;
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    return _first->prev;
}
template<class C>
std::ostream& operator<< (std::ostream& os, const LinkedList<C> &list)
{
    auto *node=list._first;

    os << "LinkedList: { ";
    if(node){
        do
        {
            os<<node->data << ",";
            node=node->next;
        }
        while (node!=list._first);
    }
    os << "\b }" << std::endl;
    return os;
}


#endif // LINKEDLIST_H
