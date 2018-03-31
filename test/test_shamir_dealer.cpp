/* main tests include */
#include "main_test.h"

void test_split_shamir_dealer() {

    printf("  split test...");

    std::string buf;
    unsigned int p = 11;
    ShamirDealer* sd = new ShamirDealer(p);
    bool check = true;

    std::string data = "2";
    List<std::string>* sl;
    unsigned int t = 3;
    unsigned int n = 5;
    sl = sd->split(data, t, n);
    if(!sl) check = false;
    if(sl->len() != n) check = false;

    // print list
    /*
    printf("\nsl: ");
    if(!!sl) {
        for(unsigned int i = 0; i < sl->len(); i++) {
            printf("\nsl[%d] = '%s'", i, sl->get(i).c_str());
        }
        printf("\n");
    }
    */
 
    // cleanup
    if(!!sl) delete sl;
    if(!!sd) delete sd;

    if(!check) {
        printf("Error on split\n");
        return;
    }
 
    printf("Ok\n");
}

void test_join_shamir_dealer() {

    printf("  join test...");

    std::string buf;
    unsigned int p = 5;
    ShamirDealer* sd = new ShamirDealer(p);
    bool check = true;

    std::string data = "fake data";
    List<std::string>* sl = new List<std::string>();
    std::string rv = sd->join(sl);

    if(rv.empty()) check = false;
    if(rv.compare(data) != 0) check = false;

    // cleanup
    if(!!sl) delete sl;

    if(!check) {
        printf("Error on split\n");
        return;
    }
 
    printf("Ok\n");
}

/* shamir_dealer tests */
void test_shamir_dealer() {

    test_split_shamir_dealer();
    // test_join_shamir_dealer();
   
}
