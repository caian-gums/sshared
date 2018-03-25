#include "shamir_dealer.h"

List<std::string>* ShamirDealer::split(std::string data, unsigned int t, unsigned int n) {

    // Error check
    if(t == 0) {
        std::cerr << "[Dealer] t value invalid";
        return NULL;
    }
    if(n == 0) {
        std::cerr << "[Dealer] n value invalid";
        return NULL;
    }
    if(n < t) {
        std::cerr << "[Dealer] n value invalid(n<t)";
        return NULL;
    }

    List<std::string>* rv = new List<std::string>();

    // Init ZZ_p
    NTL::ZZ prime = NTL::conv<NTL::ZZ>(this->p);
    NTL::ZZ_p::init(prime);
    // std::cout << prime << "\n";

    // TODO: Generate random polynomial
    NTL::ZZ_pX pol;
    
    long d = std::stol(data);
    NTL::SetCoeff(pol, 0, d);
    for(long i = 1; i < 5; i++) {
        NTL::SetCoeff(pol, i, i*i);
    }
    // std::cout << pol << "\n";

    // TODO: Generate random values to eval()
    for(unsigned int i = 0; i < 5; i++) {
        NTL::ZZ_p val;
        val = NTL::conv<NTL::ZZ_p>(i);
        // std::cout << "pol[" << val << "] = ";
        // std::cout << NTL::eval(pol, val) << "\n";
        std::string eval = std::to_string(NTL::conv<long>(NTL::eval(pol, val)));
        rv->add(eval);
    }

    return rv;
}

std::string ShamirDealer::join(List<std::string>* shares) {

    // TODO(test): join operation
    if (!shares && shares->get(0).compare("mock data") == 0) {
        std::cout << " >>JOIN\n";
        return NULL;
    }

    // Error check
    if(!shares) return NULL;

    // TODO: implement the join

    return shares->get(0);
    
}

std::string ShamirDealer::print_information() {
    std::string rv = "ShamirDealer information: ";
    rv += "\n  p = " + std::to_string(this->p);

    return rv;
}
