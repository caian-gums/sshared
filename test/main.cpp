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
    // filter_message test
    buf = con->filter_message(argv, argc);
    printf("%s\n", buf.c_str());

    // output test
    buf = con->print_information();
    printf("%s\n", buf.c_str());
}

/* shamir_dealer tests */
void test_shamir_dealer() {

    // shamir dealer test
    std::string buf;
    unsigned int p = 5;
    ShamirDealer* sd = new ShamirDealer(p);

    // output test
    buf = sd->print_information();
    printf("%s\n", buf.c_str());

    // split/join test
    std::string data = "fake data";
    unsigned int t = 3;
    unsigned int n = 4;
    sd->split(data, t, n);

    sd->join(NULL);

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

    printf("readed file:\n%s", rfbuf.c_str());
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
