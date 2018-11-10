#include <iostream>
#include <string>

#include "controller.h"
#include "shamir_dealer.h"

#include "readable_file.h"
#include "writable_file.h"


int main(int argc, const char* argv[]) {

    SS::Controller* con = new SS::Controller();
    con->filter_message(argv, argc);

    // cleanup
    delete con;
    return 0;
}
