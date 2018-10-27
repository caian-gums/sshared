#include <iostream>
#include <string>

#include "controller.h"
#include "shamir_dealer.h"

#include "readable_file.h"
#include "writable_file.h"


int main(int argc, char* argv[]) {

    Controller* con = new Controller();
    con->filter_message(argv, argc);

    std::cout << con << std::endl;

    unsigned int p = 5;
    ShamirDealer* sd = new ShamirDealer(p);
    std::cout << sd << std::endl;

    // cleanup
    delete con;
    delete sd;

    return 0;
}
