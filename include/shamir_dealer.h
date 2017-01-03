#ifndef SHAMIRDEALER_H
#define SHAMIRDEALER_H

#include "dealer.h"

class ShamirDealer : public Dealer {
public:

    ShamirDealer(unsigned int prime) : p(prime) { }
    ~ShamirDealer() { }

    // test method
    std::string print_information();

private:
    // attributes
    unsigned int p;

};
#endif
