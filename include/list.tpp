// List template implementation

template <class T>
List<T>::List() {}

template <class T>
List<T>::~List() {
    this->list.clear();
}

template <class T>
void List<T>::add(T el) {
    this->list.push_back(el);
}

template <class T>
void List<T>::remove() {
    this->list.pop_back();
}

template <class T>
T List<T>::get(unsigned int pos) {
    return this->list[pos];
}

template <class T>
unsigned int List<T>::len() {
    return this->list.size();
}
