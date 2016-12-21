#include <iostream>
#include <stdio.h>
#include <string>

#include "controller.h"


int main(int argc, char* argv[]) {

    std::string buf;
    Controller* con = new Controller();
    buf = con->filter_message(argv, argc);
    printf("%s\n", buf.c_str());

    buf = con->print_information();
    printf("%s\n", buf.c_str());


    return 0;
}
