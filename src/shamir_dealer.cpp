#include "shamir_dealer.h"

void ShamirDealer::split(std::string data, unsigned int t, unsigned int n) {
    // split method
    printf("Split method\n");
    
    printf("  data: '%s'\n", data.c_str());
    printf("  t: %u\n", t);
    printf("  n: %u\n", n);
    printf("  p: %u\n", this->p);
}

void ShamirDealer::join(void* shares) {
    // join method
    printf("Join method\n");
    
    printf("  p: %u\n", this->p);
}

std::string ShamirDealer::print_information() {
    std::string rv = "ShamirDealer information: ";
    rv += "\n  p = " + std::to_string(this->p);

    return rv;
}
