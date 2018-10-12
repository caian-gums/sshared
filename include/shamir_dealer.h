#ifndef SHAMIRDEALER_H
#define SHAMIRDEALER_H

#include <NTL/ZZ_p.h>
#include <NTL/ZZ_pX.h>
#include "dealer.h"

class ShamirDealer : public Dealer {
public:

    ShamirDealer(unsigned long prime) : p(prime) { }

    /* split method splits a message or data in 'n' parts with a 
     * minimum 't' parts.
     * 
     *  @param  t           minimum number os parts required to 
     *                      reconstruct the secret
     *  @param  n           number of parts to be splited
     *
     *  @return ShareList object with all the parts or
     *  NULL on fail
     */
    ShareList* split(std::string data, unsigned int t, unsigned int n);

    /* join method try reconstruct the secret with the given parts
     * 
     *  @param  shares      parts of the secret as a ShareList
     *
     *  @return std::string of the join operation or NULL on fail
     */
    std::string join(ShareList* shares);

    // test method
    std::string print_information();

private:
    // attributes
    unsigned long p;

};
#endif
