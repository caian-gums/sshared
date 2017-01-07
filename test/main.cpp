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

void test_shamir_dealer() {

    // shamir dealer test
    std::string buf;
    unsigned int p = 5;
    ShamirDealer* sd = new ShamirDealer(p);

    // output test
    buf = sd->print_information();
    printf("%s\n", buf.c_str());

}

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
    
    return 0;
}
