/* main tests include */
#include "main_test.h"

/* shamir_dealer tests */
void test_shamir_dealer() {

    // shamir dealer test
    std::string buf;
    unsigned int p = 5;
    ShamirDealer* sd = new ShamirDealer(p);
    bool check = true;

    // TEST: output test
    /*
    printf("  output test...");
    buf = sd->print_information();
    printf("\n%s\n", buf.c_str());
    printf("Ok\n");
    */


    // TEST: split test
    printf("  split test...");
    std::string data = "fake data";
    List<std::string>* sl;
    unsigned int t = 3;
    unsigned int n = 5;
    sl = sd->split(data, t, n);
    if(!sl) check = false;
    if(sl->len() != n) check = false;

    // cleanup
    if(!!sl) delete sl;

    if(!check) {
        printf("Error on split\n");
        delete sd;
        return;
    }

    // print list
    /*
    printf("\nsl: ");
    for(unsigned int i = 0; i < sl->len(); i++) {
        printf("\nsl[%d] = '%s'", i, sl->get(i).c_str());
    }
    printf("\n");
    */
    

    printf("Ok\n");
    // TEST: join test
    /*
    printf("  join test...");
    std::string rv = sd->join(sl);
    if(rv.empty()) check = false;
    if(rv.compare(data) != 0) check = false;

    if(!check) {
        printf("Error on join\n");
        delete sd;
        return;
    }

    // print return
    //printf("\nrv = '%s'\n", rv.c_str());

    printf("Ok\n");
    */

    // cleanup
    delete sd;

}
