#ifndef SHAMIRDEALER_H
#define SHAMIRDEALER_H

#include "dealer.h"

class ShamirDealer : public Dealer {
public:

    ShamirDealer(unsigned int prime) : p(prime) { }
    ~ShamirDealer() { }

    /* split method splits a message or data in 'n' parts with a 
     * minimum 't' parts.
     * 
     *  @param  t           minimum number os parts required to 
     *                      reconstruct the secret
     *  @param  n           number of parts to be splited
     *
     *  @return void.
     */
    void split(std::string data, unsigned int t, unsigned int n);

    /* join method try reconstruct the secret with the given parts
     * 
     *  @param  shares      parts of the secret
     *
     *  @return void.
     */
    void join(void* shares);

    // test method
    std::string print_information();

private:
    // attributes
    unsigned int p;

};
#endif
