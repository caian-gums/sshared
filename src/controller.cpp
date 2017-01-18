#include "controller.h"


Controller::Controller() {
    this->t = 0;
    this->n = 0;
}

bool Controller::filter_message(char* mes[], int size) {

    // initial check
    if(size < 2) {
        std::cerr << "[Controller] Number of arguments incorrect. Use -h (help)\n";
        return false;
    }

    // print help
    if(mes[1][1] == 'h') {
        this->print_help();
        return true;
    }

    // check if split or join was passed
    std::string sj = mes[1];
    if(sj.compare("split") != 0 && sj.compare("join") != 0) {
        std::cerr << "[Controller] Pass the operation (split or join). Use -h (help)\n";
        return false;
    }
    int nsize = size - 1;

    // check for number of arguments
    if(nsize % 2 == 0 || nsize < 2) {
        std::cerr << "[Controller] Number of arguments incorrect. Use -h (help)\n";
        return false;
    }

    for(int i = 2; i < nsize; i += 2)
        if(!this->set_value(mes[i], mes[i+1]))
            return false;

    return true;

}

void Controller::split() {

}

void Controller::join() {

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
    std::cout << "sshared lib help information: \n";
    std::cout << "Usage:\n";
    std::cout << "./sshared (<operation> <args>)|(-h)\n";
    std::cout << "  operation:\n";
    std::cout << "      - split\n";
    std::cout << "      - join\n";
    std::cout << "  arguments:\n";
    std::cout << "      - i: input file\n";
    std::cout << "      - t: minimum shares\n";
    std::cout << "      - n: number of shares\n";
    std::cout << "      - h: help information\n";
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
