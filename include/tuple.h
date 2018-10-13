#ifndef TUPLE_H
#define TUPLE_Ho

#include <iostream>

template<class S, class R>
class Tuple {
private:
    S _first;
    R _second;
public:
    Tuple(S first, R second): _first(first), _second(second) {}
    ~Tuple() {}

    // Get of parameters
    S first() { return _first; }
    R second() { return _second; }

    friend std::ostream & operator<<(std::ostream & os, Tuple t)  {
        os << t.first() << "," << t.second();
        return os;
    } 
};

#endif
