#include "shamir_dealer.h"

TupleList* ShamirDealer::split(std::string data, unsigned int t, unsigned int n) {

    // Error check
    if(t == 0) {
        std::cerr << "[sshared] Error: t value invalid" << std::endl;
        return NULL;
    }
    if(n == 0) {
        std::cerr << "[sshared] Error: n value invalid" << std::endl;
        return NULL;
    }
    if(n < t) {
        std::cerr << "[sshared] Error: n value invalid(n<t)" << std::endl;
        return NULL;
    }

    TupleList* rv = new TupleList();

    // Init ZZ_p
    NTL::ZZ prime = NTL::conv<NTL::ZZ>(this->p);
    NTL::ZZ_p::init(prime);

    NTL::ZZ_pX pol;
    
    const char * data_char = data.c_str();
    unsigned long d = static_cast<unsigned long>(data_char[0]);

    for(unsigned long i = 1; i < t; i++) {
        NTL::ZZ_p coef = NTL::random_ZZ_p();
        NTL::SetCoeff(pol, i, coef);
    }
    NTL::SetCoeff(pol, 0, d);

    for(unsigned int i = 0; i < n; i++) {
        NTL::ZZ_p val = NTL::random_ZZ_p();
        ss_Y eval = std::to_string(NTL::conv<long>(NTL::eval(pol, val)));
        ss_X index = std::to_string(NTL::conv<long>(val));
        Tuple<ss_Y, ss_X> tuple(index, eval);

        rv->add(tuple);
    }

    return rv;
}

std::string ShamirDealer::join(TupleList* shares) {

    // Error check
    if(!shares) {
        std::cerr << "[sshared] Error: no shares passed" << std::endl;
        return NULL;
    }

    // Init ZZ_p
    NTL::ZZ prime = NTL::conv<NTL::ZZ>(this->p);
    NTL::ZZ_p::init(prime);
 
    // create the vectors of coefficients and index
    NTL::Vec<NTL::ZZ_p> coef;
    NTL::Vec<NTL::ZZ_p> ind;

    // sets length of vectors
    coef.SetLength((long) shares->len());
    ind.SetLength((long) shares->len());

    // TODO: Create a better logic to this matching part
    for(long i = 0; i < shares->len(); i++) {
        ind[i] = NTL::conv<NTL::ZZ_p>(std::stoul(shares->get(i).first()));
        coef[i] = NTL::conv<NTL::ZZ_p>(std::stoul(shares->get(i).second()));
    }

    // recreate the polynomial
    NTL::ZZ_pX pol;

    // interpolate to find the polynomial
    pol = NTL::interpolate(ind, coef);

    NTL::ZZ_p zero_index;
    zero_index = NTL::conv<NTL::ZZ_p>((long) 0);
    int result = NTL::conv<int>(NTL::eval(pol, zero_index));
    char result_char = static_cast<char>(result);
    std::string eval(1, result_char);

    return eval;
}
