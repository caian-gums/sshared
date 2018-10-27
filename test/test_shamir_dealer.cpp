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

    TupleList* tl;
    unsigned int t = 3;
    unsigned int n = 5;
    tl = sd->split(data, t, n);

    if(!tl) check = false;
    if(tl->len() != n) check = false;
    
    // cleanup
    if(!!tl) delete tl;
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

    TupleList* tl = new TupleList();
    // Match the known values from split
    // the secret must not be known
    // tl->add(share_0); // 'a' = 97
    tl->add(share_1);
    tl->add(share_2);
    tl->add(share_3);
    tl->add(share_4);
    std::string rv = sd->join(tl);

    if(rv.empty()) check = false;
    if(rv.compare(data) != 0) check = false;

    // cleanup
    if(!!tl) delete tl;
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
