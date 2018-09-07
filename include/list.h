#ifndef LIST_H
#define LIST_H

#include <vector>

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

// List template implementation
#include "list.tpp"

#endif
