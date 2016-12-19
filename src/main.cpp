#include <iostream>
#include <stdio.h>
#include <string>

#include "controller.h"


int main(int argc, char* argv[]) {

    std::string buf;
    Controller* con = new Controller();
    buf = con->filter_message(argv, argc);
    printf("%s", buf.c_str());


    return 0;
}
