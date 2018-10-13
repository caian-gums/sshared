/* main tests include */
#include "main_test.h"

// Mock values
static const unsigned long p = 104471;
static const std::string data = "a";

// static const ShareTuple share_0("0", "97");
static const ShareTuple share_1("1", "111");
static const ShareTuple share_2("2", "187");
static const ShareTuple share_3("3", "379");
static const ShareTuple share_4("4", "741");

void test_split_shamir_dealer() {

    std::cout << "  split test...";

    ShamirDealer* sd = new ShamirDealer(p);
    bool check = true;

    ShareList* sl;
    unsigned int t = 3;
    unsigned int n = 5;
    sl = sd->split(data, t, n);

    if(!sl) check = false;
    if(sl->len() != n) check = false;

    // print list
    // std::cout << "\nsl: ";
    // if(!!sl) {
    //     for(unsigned int i = 0; i < sl->len(); i++) {
    //         std::cout << "\nsl[" <<  i << "] = '" << sl->get(i) << "'";
    //     }
    //     std::cout << std::endl;
    // }
    
 
    // cleanup
    if(!!sl) delete sl;
    if(!!sd) delete sd;

    if(!check) {
        std::cout << "Error" << std::endl;
        return;
    }
 
    std::cout << "Ok" << std::endl;
}

void test_join_shamir_dealer() {

    std::cout << "  join test...";

    ShamirDealer* sd = new ShamirDealer(p);
    bool check = true;

    ShareList* sl = new ShareList();
    // Match the known values from split
    // the secret must not be known
    // sl->add(share_0); // 'a' = 97
    sl->add(share_1);
    sl->add(share_2);
    sl->add(share_3);
    sl->add(share_4);
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
        std::cout << "Error" << std::endl;
        return;
    }
 
    std::cout << "Ok" << std::endl;
}

/* shamir_dealer tests */
void test_shamir_dealer() {

    test_split_shamir_dealer();
    test_join_shamir_dealer();
   
}
