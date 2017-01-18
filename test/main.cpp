#include <iostream>
#include <stdio.h>
#include <string>

/* controller include */
#include "controller.h"

/* dealer includes */
#include "shamir_dealer.h"

/* file includes */
#include "readable_file.h"
#include "writable_file.h"

/* list includes */
#include "list.h"

/* controller tests */
void test_controller(int argc, char* argv[]) {

    // controler test
    std::string buf;
    Controller* con = new Controller();

    bool check = true;
    // TEST: filter_message
    printf("  filter_message...");
    check = con->filter_message(argv, argc);
    if(!check) {
        printf("Error on filter message\n");
        return;
    }

    printf("Ok\n");

    /* output test
    buf = con->print_information();
    printf("%s\n", buf.c_str());
    */
}

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
    List<std::string>* sl = NULL;
    unsigned int t = 3;
    unsigned int n = 5;
    sl = sd->split(data, t, n);
    if(!sl) check = false;
    if(sl->len() != n) check = false;

    if(!check) {
        printf("Error on split\n");
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
    printf("  join test...");
    std::string rv = sd->join(sl);
    if(rv.empty()) check = false;
    if(rv.compare(data) != 0) check = false;

    if(!check) {
        printf("Error on join\n");
        return;
    }

    // print return
    //printf("\nrv = '%s'\n", rv.c_str());

    printf("Ok\n");

}

/* file tests */
void test_file() {

    // file name
    std::string fp = "test.txt";

    // writable file
    WritableFile* wf = new WritableFile(fp);
    wf->open();
    std::string wfbuf = "Test file.\n1 2 3 test";
    wf->write(wfbuf);
    wf->close();

    // readable file
    ReadableFile* rf = new ReadableFile(fp);
    rf->open();
    std::string rfbuf = rf->read();
    rf->close();

    /* See the files:
    printf("wfbuf: '%s'\nrfbuf: '%s'\n", wfbuf.c_str(), rfbuf.c_str());
    */

    bool check = true;
    // TEST: compare test
    printf("  compare files test...");
    if(rfbuf.compare(wfbuf) == 0) check = true;
    else check = false;
    if(!check) {
        printf("Error on compare\n");
        return;
    }

    printf("Ok\n");
    
}

/* list tests */
void test_list() {
    // List creation
    List<int>* il = new List<int>();
    List<std::string>* sl = new List<std::string>();

    // TEST: add test
    bool check = true;
    printf("  add test...");

    // int test
    int el0 = 3;
    int el1 = 5;
    int el2 = 7;
    il->add(el0);
    il->add(el1);
    il->add(el2);
    if(il->get(0) != el0) check = false;
    if(il->get(1) != el1) check = false;
    if(il->get(2) != el2) check = false;
    if(!check) {
        printf("Error on int\n");
        return;
    }

    // string test
    std::string se0 = "test0";
    std::string se1 = "test2";
    std::string se2 = "testtest";
    sl->add(se0);
    sl->add(se1);
    sl->add(se2);
    if(sl->get(0).compare(se0) != 0) check = false;
    if(sl->get(1).compare(se1) != 0) check = false;
    if(sl->get(2).compare(se2) != 0) check = false;
    if(!check) {
        printf("Error on string\n");
        return;
    }
    
    printf("Ok\n");

    // TEST: get test
    printf("  get test...");

    // int test
    if(il->get(0) != el0) check = false;
    if(il->get(1) != el1) check = false;
    if(il->get(2) != el2) check = false;
    if(!check) {
        printf("Error on int\n");
        return;
    }

    // string test
    if(sl->get(0).compare(se0) != 0) check = false;
    if(sl->get(1).compare(se1) != 0) check = false;
    if(sl->get(2).compare(se2) != 0) check = false;
    if(!check) {
        printf("Error on string\n");
        return;
    }

    printf("Ok\n");
    
    // TEST: len test
    printf("  len test..");

    // int test
    if(il->len() != 3) check = false;
    if(!check) {
        printf("Error on int\n");
        return;
    }

    // string test
    if(sl->len() != 3) check = false;
    if(!check) {
        printf("Error on string\n");
        return;
    }
    
    printf("Ok\n");

    // TEST: remove test
    printf("  remove test..");

    // int test
    il->remove();
    il->remove();
    il->remove();
    if(il->len() != 0) check = false;
    if(!check) {
        printf("Error on int\n");
        return;
    }

    // string test
    sl->remove();
    sl->remove();
    sl->remove();
    if(sl->len() != 0) check = false;
    if(!check) {
        printf("Error on string\n");
        return;
    }
    
    printf("Ok\n");

    return;
}

// main test function
int main(int argc, char* argv[]) {

    printf("[test] controller... \n");
    test_controller(argc, argv);

    printf("\n");
    printf("[test] shamir dealer... \n");
    test_shamir_dealer();

    printf("\n");
    printf("[test] file... \n");
    test_file();

    printf("\n");
    printf("[test] list... \n");
    test_list();
    
    return 0;
}
