#include "controller.h"

std::string Controller::filter_message(char* mes[], int size) {

    int i = 0;
    std::string out;
    while(i < size) {
        out += "mes[" + std::to_string(i) + "]: " + mes[i] + "\n";
        i++;
    }
    out = "size: " + std::to_string(size) + "\n" + out;
    
    return out;

}
