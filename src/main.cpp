#include <iostream>
#include <string>

#include "controller.h"
#include "shamir_dealer.h"

#include "readable_file.h"
#include "writable_file.h"


int main(int argc, char* argv[]) {

    std::string buf;
    Controller* con = new Controller();
    con->filter_message(argv, argc);

    buf = con->print_information();
    std::cout << buf.c_str() << std::endl;

    unsigned int p = 5;
    ShamirDealer* sd = new ShamirDealer(p);
    buf = sd->print_information();
    std::cout << buf.c_str() << std::endl;

    // cleanup
    delete con;
    delete sd;

    return 0;
}
