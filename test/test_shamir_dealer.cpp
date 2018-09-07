/* main tests include */
#include "main_test.h"

void test_split_shamir_dealer() {

    std::cout << "  split test...";

    std::string buf;
    unsigned int p = 104471;
    ShamirDealer* sd = new ShamirDealer(p);
    bool check = true;

    std::string data = "ab";
    List<std::string>* sl;
    unsigned int t = 3;
    unsigned int n = 5;
    sl = sd->split(data, t, n);

    if(!sl) check = false;
    if(sl->len() != n) check = false;

    // print list
    
    std::cout << "\nsl: ";
    if(!!sl) {
        for(unsigned int i = 0; i < sl->len(); i++) {
            std::cout << "\nsl[" <<  i << "] = '" << sl->get(i) << "'";
        }
        std::cout << std::endl;
    }
    
 
    // cleanup
    if(!!sl) delete sl;
    if(!!sd) delete sd;

    if(!check) {
        std::cout << "Error on split" << std::endl;
        return;
    }
 
    std::cout << "Ok" << std::endl;
}

void test_join_shamir_dealer() {

    std::cout << "  join test...";

    unsigned int p = 103;
    ShamirDealer* sd = new ShamirDealer(p);
    bool check = true;

    std::string data = "a";
    List<std::string>* sl = new List<std::string>();
    // Match the known values from split
    // the secret must not be known
    // sl->add("a");
    sl->add("8");
    sl->add("84");
    sl->add("70");
    sl->add("20");
    std::string rv = sd->join(sl);

    if(rv.empty()) check = false;
    if(rv.compare(data) != 0) check = false;

    // read rv
    /*
    if(!rv.empty()) {
        std::cout << "\nrv = " << rv << std::endl;
    }
    */

    // cleanup
    if(!!sl) delete sl;
    if(!!sd) delete sd;

    if(!check) {
        std::cout << "Error on join" << std::endl;
        return;
    }
 
    std::cout << "Ok" << std::endl;
}

/* shamir_dealer tests */
void test_shamir_dealer() {

    test_split_shamir_dealer();
    test_join_shamir_dealer();
   
}
