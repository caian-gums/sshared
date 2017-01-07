#ifndef DEALER_H
#define DEALER_H

#include <string>

class Dealer {
public:

    /* [VIRTUAL] split method splits a message or data in 'n' parts with a 
     * minimum 't' parts.
     * 
     *  @param t        minimum number os parts required to 
     *                  reconstruct the secret
     *  @param n        number of parts to be splited
     *
     *  @return void.
     */
    virtual void split(std::string data, unsigned int t, unsigned int n) = 0;

    /* [VIRTUAL] join method try reconstruct the secret with the given parts
     * 
     *  @param shares   parts of the secret
     *
     *  @return void.
     */
    virtual void join(void* shares) = 0;

};
 
#endif
