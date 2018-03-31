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
    // discover the prime
    // std::cout << prime << "\n";

    // TODO: Generate random polynomial
    NTL::ZZ_pX pol;
    
    long d = std::stol(data);
    NTL::SetCoeff(pol, 0, d);
    for(long i = 1; i < 4; i++) {
        NTL::SetCoeff(pol, i, i*i);
    }
    // discover the polynomial
    // std::cout << "\n" << pol << "\n";

    // TODO: Generate random values to eval()
    for(unsigned int i = 0; i < 5; i++) {
        NTL::ZZ_p val;
        val = NTL::conv<NTL::ZZ_p>(i);
        // print eval values
        // std::cout << "pol[" << val << "] = ";
        // std::cout << NTL::eval(pol, val) << "\n";
        std::string eval = std::to_string(NTL::conv<long>(NTL::eval(pol, val)));
        rv->add(eval);
    }

    return rv;
}

std::string ShamirDealer::join(List<std::string>* shares) {

    // Error check
    if(!shares) {
        std::cerr << "[Dealer] no shares passed";
        return NULL;
    }

    // Init ZZ_p
    NTL::ZZ prime = NTL::conv<NTL::ZZ>(this->p);
    NTL::ZZ_p::init(prime);
    // discover the prime
    // std::cout << prime << "\n";

 
    // Create the vectors of coefficients and index
    NTL::Vec<NTL::ZZ_p> coef;
    NTL::Vec<NTL::ZZ_p> ind;

    // Sets length of vectors
    coef.SetLength((long) shares->len());
    ind.SetLength((long) shares->len());

    // TODO: Create a better logic to this matching part
    for(long i = 0; i < 4; i++) {
        coef[i] = NTL::conv<NTL::ZZ_p>(std::stol(shares->get(i)));
        ind[i] = NTL::conv<NTL::ZZ_p>((long) (i+1));
    }
    // std::cout << "\n";
    // std::cout << "ind = " << ind << "\n";
    // std::cout << "coef = " << coef << "\n";
    // std::cout << "\n";

    // Create the polynomial
    NTL::ZZ_pX pol;

    // Interpolate to find the polynomial
    pol = NTL::interpolate(ind, coef);
    // discover the polynomial
    // std::cout << "\n" << pol << "\n";

    NTL::ZZ_p zero_index;
    zero_index = NTL::conv<NTL::ZZ_p>((long) 0);
    std::string eval = std::to_string(NTL::conv<long>(NTL::eval(pol, zero_index)));
    // print eval value
    // std::cout << "pol[" << zero_index << "] = ";
    // std::cout << NTL::eval(pol, val) << "\n";

    return eval;
    
}

std::string ShamirDealer::print_information() {
    std::string rv = "ShamirDealer information: ";
    rv += "\n  p = " + std::to_string(this->p);

    return rv;
}
