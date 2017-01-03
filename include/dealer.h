#ifndef DEALER_H
#define DEALER_H

#include <string>

class Dealer {
public:

    /* split method splits a message or data in 'n' parts with a 
     * minimum 't' parts.
     * 
     *  @param n        number of parts to be splited
     *  @param t        minimum number os parts required to 
     *                  reconstruct the secret
     *
     *  @return void.
     */
    void split(std::string data, unsigned int n, unsigned int t);

    /* join method try reconstruct the secret with the given parts
     * 
     *  @param shares   parts of the secret
     *
     *  @return void.
     */
    void join(void* shares);

};
 
#endif
