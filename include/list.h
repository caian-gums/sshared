#ifndef LIST_H
#define LIST_H

#include <vector>

namespace SS
{
    template <class T>
    class List {
    public:

        // Constructor
        List();
        ~List();

        /* add method adds the given element el on the
        * list
        *
        *  @param  el      element to be inserted
        *
        *  @return void
        */
        void add(T el);

        /* remove method remove the last inserted element
        * 
        *  @return void
        */
        void remove();

        /* len method return the size of the list
        *
        *  @return the size of the list
        */
        unsigned int len();

        /* get method get the reference to the given element
        * on specific position
        *
        *  @param  pos     position of the element on
        *                  the list
        * 
        *  @return the element or null
        */
        T get(unsigned int pos);

    private:
        // attributes
        // inside list
        std::vector<T>* list;

    };
}

template <class T>
SS::List<T>::List() {
    this->list = new std::vector<T>();
}

template <class T>
SS::List<T>::~List() {
    this->list->clear();
    delete this->list;
}

template <class T>
void SS::List<T>::add(T el) {
    this->list->push_back(el);
}

template <class T>
void SS::List<T>::remove() {
    this->list->pop_back();
}

template <class T>
T SS::List<T>::get(unsigned int pos) {
    return this->list->at(pos);
}

template <class T>
unsigned int SS::List<T>::len() {
    return this->list->size();
}

#endif
