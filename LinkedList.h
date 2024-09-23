#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <initializer_list>
#include <iostream>
#include "NodeIterator.h"
#include "ReverseIterator.h"

template <typename T>
class LinkedList
{
private:
    Node<T>* head = nullptr, *tail = nullptr;
    int _size = 0;

    void push_front(Node<T>* node);
    void push_back(Node<T>* node);

    void one_node_pop();
    void remove(Node<T>* target);

    void insert_before(Node<T>* target, Node<T>* data);
    Node<T>* search(const T& target);

    Node<T>* create_node(const T& data);
    //void add_first_node(const T& data);
    void add_first_node(Node<T>* node);

    void copy_list(Node<T> &list);
    void clear_list();
public:
    typedef NodeIterator<T> iterator;
    typedef ReverseIterator<T> reverse_iterator;
    //typedef ConstIterator<T> const_iterator;



    LinkedList();
    LinkedList(const std::initializer_list<T>& list);

    LinkedList(const LinkedList<T>& list);

    ~LinkedList();

    LinkedList<T>& operator=(const LinkedList<T>& list);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out,
            const LinkedList<U>& list);

    template <typename U>
    friend LinkedList<U> operator+(const LinkedList<U>& list1,
                                   const LinkedList<U>& list2);

    int size() const;
    void push_front(const T& data);
    void push_back(const T& data);
    void pop_front();
    void pop_back();

    T& front(); ///return data from head
    T& back();/// return data from tail
    const T& front() const; ///return data from head
    const T& back() const;/// return data from tail

    bool empty() const;

    bool contains(const T& data);

    void remove(const T& data); ///remove the first instance of data
    void insert_before(const T& targetData, const T& newData);
    void insert_after(const T& targetData, const T& newData);

    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
    //const_iterator cbegin();
    //const_iterator cend();
};

#include "LinkedList.cpp"
#endif
