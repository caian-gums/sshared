// List template implementation

template <class T>
List<T>::List() {
    this->list = new std::vector<T>();
}

template <class T>
List<T>::~List() {
    this->list->clear();
    delete this->list;
}

template <class T>
void List<T>::add(T el) {
    this->list->push_back(el);
}

template <class T>
void List<T>::remove() {
    this->list->pop_back();
}

template <class T>
T List<T>::get(unsigned int pos) {
    return this->list->at(pos);
}

template <class T>
unsigned int List<T>::len() {
    return this->list->size();
}
