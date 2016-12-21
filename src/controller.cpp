#include "controller.h"

std::string Controller::filter_message(char* mes[], int size) {

    // return value
    std::string rv;
    // check for number of arguments
    if(size % 2 == 0 || size < 2) {
        rv = "Error on usage. Number of arguments incorrect";
        return rv;
    }

    int i = 1;
    while(i < size) {
        rv += "mes[" + std::to_string(i) + "]: " + mes[i] + "\n";
        rv += "mes[" + std::to_string(i) + "]: " + mes[i+1] + "\n";
        // two positions
        i = i + 2;
    }
    rv = "size: " + std::to_string(size) + "\n" + rv;
    
    return rv;

}
