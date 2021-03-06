#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
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
class SLinkedList
{
public:
    SLinkedList();

    //getters
    const T &at(const int &pos) const;
    T& at(const int &pos);
    T value(const int &pos) {return getNode(pos)->data;}
    const T &first() const;
    const T &last() const;

    //add
    void append(const T &value);
    void prepend(const T &value);
    void insert(const int &before, const T &value);

    void replace(const int &pos, const T &value);

    //remove
    void remove(const int &pos);
    void removeLast();
    void removefirst();


    // stat
    int size() const {return _size;}
    int count() const {return size();}
    int length() const {return size();}
    bool isEmpty(){return size();}


    //operators
    operator bool(){return isEmpty();}
    T& operator [](const int &pos){return at(pos);}
    SLinkedList<T> & operator <<(const T &value){append(value); return *this;}
    SLinkedList<T> & operator +=(const T &value) {append(value); return *this;}
    template<class C>
    friend std::ostream& operator<<(std::ostream& os, const SLinkedList<C> &list);

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
SLinkedList<T>::SLinkedList()
{

}

template <class T>
Node<T> *SLinkedList<T>::allocNode(const T &value)
{
    incSize();
    return new Node<T>(value);
}

template<class T>
void SLinkedList<T>::append(const T &value)
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
        _first->prev=newNode;
        newNode->next=_first;
        newNode->prev=tmp;
        tmp->next=newNode;
    }
}

template<class T>
void SLinkedList<T>::prepend(const T &value)
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
        auto last=getLastNode();
        newNode->next=_first;
        newNode->prev=last;
        _first->prev=newNode;
        last->next=newNode;
        _first=newNode;
    }
}
template<class T>
const T& SLinkedList<T>::at(const int &pos) const
{
    assert(pos<size());

    return getNode(pos)->data;
}
template<class T>
T& SLinkedList<T>::at(const int &pos)
{
    assert(pos<size());

    return getNode(pos)->data;
}

template<class T>
const T &SLinkedList<T>::first() const
{
    assert(size());
    return _first->data;
}

template<class T>
const T &SLinkedList<T>::last() const
{
    return getLastNode()->data;
}

template<class T>
void SLinkedList<T>::insert(const int &before,const T &value)
{
    assert(before<size());

    auto newNode=allocNode(value);

    auto tmp=getNode(before);

    if(tmp==_first)
        _first=newNode;

    newNode->prev=tmp->prev;
    newNode->next=tmp;
    newNode->prev->next=newNode;

}

template<class T>
void SLinkedList<T>::replace(const int &pos, const T &value)
{
    assert(pos<size());

    auto tmp=getNode(pos);
    tmp->data=value;
}

template<class T>
void SLinkedList<T>::remove(const int &pos)
{
    assert(pos<size());

    removeNode(getNode(pos));
}

template<class T>
void SLinkedList<T>::removeLast()
{
    assert(size());

    removeNode(getLastNode());
}

template<class T>
void SLinkedList<T>::removefirst()
{
    assert(size());
    removeNode(_first);
}


template<class T>
void SLinkedList<T>::removeNode(Node<T> *node)
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
Node<T> *SLinkedList<T>::getNode(const int &pos) const
{
    auto tmp=_first;

    for(int i=0; i<pos; i++)
        tmp=tmp->next;

    return tmp;
}

template<class T>
Node<T> *SLinkedList<T>::getLastNode() const
{
    return _first->prev;
}
template<class C>
std::ostream& operator<< (std::ostream& os, const SLinkedList<C> &list)
{
    auto *node=list._first;

    os << "SLinkedList: { ";
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


#endif // SLINKEDLIST_H
