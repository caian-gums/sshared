#include "controller.h"


Controller::Controller() {
    this->t = 0;
    this->n = 0;
}

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
        this->set_value(mes[i], mes[i+1]);
        rv += "mes[" + std::to_string(i) + "]: " + mes[i] + "\n";
        rv += "mes[" + std::to_string(i) + "]: " + mes[i+1] + "\n";
        // two positions
        i = i + 2;
    }
    rv = "size: " + std::to_string(size) + "\n" + rv;
    
    return rv;

}

bool Controller::set_value(char* arg, char* value) {

    if(arg[0] != '-') {
        // error on arg definition
        return false;
    }

    switch(arg[1]) {
        // input file path
        case 'i': {
            this->set_file_path(value);
            break;
        }
        // n value
        case 'n': {
            this->set_n(value);
            break;
        }
        // t value
        case 't': {
            this->set_t(value);
            break;
        }
        default:
            return false;
            break;
    }
    return true;
}

void Controller::set_t(char* value) {
    std::string v(value);
    this->t = std::stoi(v);
}

void Controller::set_n(char* value) {
    std::string v(value);
    this->n = std::stoi(v);
}

void Controller::set_file_path(char* value) {
    this->file_path = value;
}

std::string Controller::print_information() {
    std::string rv = "Controller information: ";
    rv += "\n  t = " + std::to_string(this->t);
    rv += "\n  n = " + std::to_string(this->n);
    rv += "\n  file_path = ";
    if(!this->file_path.empty()) rv += this->file_path;
    else rv += "NULL";

    return rv;
}
