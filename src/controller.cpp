#include "controller.h"


Controller::Controller() {
    this->t = 0;
    this->n = 0;
}

bool Controller::filter_message(char* mes[], int size) {

    // return value
    std::string rv;
    // check for number of arguments
    if(size % 2 == 0 || size < 2) {
        if(size == 2 && mes[1][1] == 'h') {
            this->print_help();
            return true;
        }
        std::cerr << "[Controller] Number of arguments incorrect. Use -h (help)\n";
        return false;
    }

    for(int i = 1; i < size; i += 2)
        if(!this->set_value(mes[i], mes[i+1]))
            return false;

    return true;

}

bool Controller::set_value(char* arg, char* value) {

    if(arg[0] != '-') {
        // error on arg definition
        std::cerr << "[Controller] Invalid argument passed: " << arg << "\n";
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
            std::cerr << "[Controller] Invalid option: " << arg << "\n";
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

void Controller::print_help() {
    std::cout << " << Help information >> \n";
}

std::string Controller::print_information() {
    std::string rv = "Controller information: ";
    rv += "\n  t = " + std::to_string(this->t);
    rv += "\n  n = " + std::to_string(this->n);
    rv += "\n  file_path = ";
    if(!this->file_path.empty()) rv += this->file_path;
    else rv += "<No file provided>";

    return rv;
}
