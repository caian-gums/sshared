#ifndef DEALER_H
#define DEALER_H

#include <string>
#include "list.h"

// Used in error log
#include <iostream>

class Dealer {
public:

    /* [VIRTUAL] split method splits a message or data in 'n' parts with a 
     * minimum 't' parts.
     * 
     *  @param  t           minimum number os parts required to 
     *                      reconstruct the secret
     *  @param  n           number of parts to be splited
     *
     *  @return List<std::string> object with all the parts or
     *  NULL on fail
     */
    virtual List<std::string>* split(std::string data, unsigned int t, unsigned int n) = 0;

    /* [VIRTUAL] join method try reconstruct the secret with the given parts
     * 
     *  @param  shares      parts of the secret as a
     *                      List<std::string>
     *
     *  @return std::string of the join operation or NULL on fail
     */
    virtual std::string join(List<std::string>* shares) = 0;

};
 
#endif
