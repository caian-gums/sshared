#include <iostream>
#include <stdio.h>
#include <string>

#include "controller.h"
#include "shamir_dealer.h"

#include "readable_file.h"
#include "writable_file.h"


int main(int argc, char* argv[]) {

    std::string buf;
    Controller* con = new Controller();
    buf = con->filter_message(argv, argc);
    printf("%s\n", buf.c_str());

    buf = con->print_information();
    printf("%s\n", buf.c_str());

    unsigned int p = 5;
    ShamirDealer* sd = new ShamirDealer(p);
    buf = sd->print_information();
    printf("%s\n", buf.c_str());


    return 0;
}
