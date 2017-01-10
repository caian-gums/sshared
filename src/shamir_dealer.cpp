#include "shamir_dealer.h"

List<std::string>* ShamirDealer::split(std::string data, unsigned int t, unsigned int n) {

    // Error check
    if(t == 0) return NULL;
    if(n == 0) return NULL;
    if(n < t) return NULL;

    List<std::string>* rv = new List<std::string>();

    
    for(unsigned int i = 0; i < n; i++) {
        if(i < t) rv->add(data);
        else rv->add("fill");
    }
    return rv;
}

std::string ShamirDealer::join(List<std::string>* shares) {

    // Error check
    if(!shares) return NULL;

    return shares->get(0);
    
}

std::string ShamirDealer::print_information() {
    std::string rv = "ShamirDealer information: ";
    rv += "\n  p = " + std::to_string(this->p);

    return rv;
}
