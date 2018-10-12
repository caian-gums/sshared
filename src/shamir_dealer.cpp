#include "shamir_dealer.h"

ShareList* ShamirDealer::split(std::string data, unsigned int t, unsigned int n) {

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

    ShareList* rv = new ShareList();

    // Init ZZ_p
    NTL::ZZ prime = NTL::conv<NTL::ZZ>(this->p);
    NTL::ZZ_p::init(prime);
    // discover the prime
    // std::cout << "Prime=" << prime << std::endl;

    // TODO: Generate random polynomial
    NTL::ZZ_pX pol;
    
    const char * data_char = data.c_str();
    std::cout << "ShamirDealer::split - data_char='" << data_char << "'" << std::endl;
    unsigned long d = static_cast<unsigned long>(data_char[0]);
    // std::cout << "d=" << std::hex << d << std::endl;
    NTL::SetCoeff(pol, 0, d);
    for(unsigned long i = 1; i < 4; i++) {
        NTL::SetCoeff(pol, i, i*i);
    }
    // discover the polynomial
    std::cout << "\nPolynomial=" << pol << std::endl;

    // TODO: Generate random values to eval()
    for(unsigned int i = 0; i < 5; i++) {
        NTL::ZZ_p val;
        val = NTL::conv<NTL::ZZ_p>(i);
        // print eval values
        // std::cout << "pol[" << val << "] = ";
        // std::cout << NTL::eval(pol, val) << std::endl;
        ss_Y eval = std::to_string(NTL::conv<long>(NTL::eval(pol, val)));
        ss_X index = std::to_string(i);
        Tuple<ss_Y, ss_X> tuple(index, eval);

        rv->add(tuple);
    }

    return rv;
}

std::string ShamirDealer::join(ShareList* shares) {

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
    for(long i = 0; i < shares->len(); i++) {
        ind[i] = NTL::conv<NTL::ZZ_p>(std::stoul(shares->get(i).first()));
        coef[i] = NTL::conv<NTL::ZZ_p>(std::stoul(shares->get(i).second()));
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
    std::cout << std::endl << pol << std::endl;

    NTL::ZZ_p zero_index;
    zero_index = NTL::conv<NTL::ZZ_p>((long) 0);
    int result = NTL::conv<int>(NTL::eval(pol, zero_index));
    char result_char = static_cast<char>(result);
    std::string eval(1, result_char);
    // print eval value
    // std::cout << "eval=" << eval << std::endl;

    return eval;
    
}

std::string ShamirDealer::print_information() {
    std::string rv = "ShamirDealer information: ";
    rv += "\n  p = " + std::to_string(this->p);

    return rv;
}
