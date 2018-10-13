#ifndef DEALER_H
#define DEALER_H

#include <string>
#include "list.h"
#include "tuple.h"

// Used in error log
#include <iostream>

// Value x of q(x)
typedef std::string ss_X;
// Value of q(x) based on x
typedef std::string ss_Y;

// Tuple definition
typedef Tuple<ss_X, ss_Y> ShareTuple;

// List of shares
typedef List<ShareTuple> TupleList;

class Dealer {
public:

    virtual ~Dealer() { }

    /* [VIRTUAL] split method splits a message or data in 'n' parts with a 
     * minimum 't' parts.
     * 
     *  @param  t           minimum number os parts required to 
     *                      reconstruct the secret
     *  @param  n           number of parts to be splited
     *
     *  @return TupleList object with all the parts or
     *  NULL on fail
     */
    virtual TupleList* split(std::string data, unsigned int t, unsigned int n) = 0;

    /* [VIRTUAL] join method try reconstruct the secret with the given parts
     * 
     *  @param  shares      parts of the secret as a TupleList
     *
     *  @return std::string of the join operation or NULL on fail
     */
    virtual std::string join(TupleList* shares) = 0;

};
 
#endif
