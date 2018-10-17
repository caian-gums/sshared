#include "controller.h"

Controller::~Controller() {
    if(!dealer) delete dealer;
}

bool Controller::filter_message(const char* mes[], int size) {

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

    // set values on Controller
    for(int i = 2; i < nsize; i += 2) {
        if(mes[i][1] == 'l') {
            if(!this->set_list_filepath(mes, i, size - i)) {
                std::cerr << "[Controller] Number of arguments incorrect. Use -h (help)\n";
                return false;
            }
            break;
        }
        if(!this->set_value(mes[i], mes[i+1])) {
            return false;
        }
    }

    // do split/join operation
    if(sj.compare("split") == 0) {
        this->split();
    } else if (sj.compare("join") == 0) {
        this->join();
    } else {
        return false;
    }

    return true;

}

void Controller::split() {
    // TODO: support others dealers
    if(this->dealer_type.empty() || this->dealer_type.compare("shamir") == 0) {
        this->dealer = new ShamirDealer(this->_p);

        // open file and read
        ReadableFile* in_file = new ReadableFile(this->_file_path);
        in_file->open();
        std::string data = in_file->read();
        in_file->close();
        delete in_file;

        // create the list of EvaluatedShares
        this->es = new EvaluetedShares();
        TupleList* tl;

        // step 1 - split each byte
        for(unsigned int i = 0; i < data.length(); i++) {
            tl = this->dealer->split(data.substr(i, 1), this->_t, this->_n);
            this->es->add(tl);
        }

        // step 2 - save to files 
        // open a file to each Share
        for(unsigned int i = 0; i < this->_n; i++) {
            std::string share_file_name = this->_file_path + ".share" + std::to_string(i);
            WritableFile* out_file = new WritableFile(share_file_name);
            out_file->open();
            // write the Shares on each file
            for(unsigned int j = 0; j < this->es->len(); j++) {
                tl = this->es->get(j);
                ShareTuple st = tl->get(i);
                std::string line = st.first() + "," + st.second() + "\n";
                out_file->write(line);
            }
            // close file
            out_file->close();
            delete out_file;
        }

        // cleanup
        delete this->dealer;
    }
}

StringList* Controller::split_string(std::string data, char delimiter) {
    std::stringstream ssdata(data);
    std::string token;
    StringList* lstring = new StringList();
    while(std::getline(ssdata, token, delimiter)) {
        lstring->add(token);
    }
    return lstring;
}

void Controller::join() {
    // TODO: suport others dealers
    if(this->dealer_type.empty() || this->dealer_type.compare("shamir") == 0) {
        this->dealer = new ShamirDealer(this->_p);

        this->es = new EvaluetedShares();

        // step 1 - open files and get the shares
        for(unsigned int i = 0; i < this->_list_file_path->len(); i++) {
            std::string share_file_name = this->_list_file_path->get(i);
            ReadableFile* in_file = new ReadableFile(share_file_name);
            in_file->open();

            // read the shares
            std::string data = in_file->read();
            StringList* lstring = this->split_string(data, '\n');
            
            // read the Shares from each file
            for(unsigned int j = 0; j < lstring->len(); j++) {
                TupleList* tl;
                if(this->es->len() == 0 || j >= this->es->len()) {
                    tl = new TupleList();
                    this->es->add(tl);
                }
                tl = this->es->get(j);
                // build the tuples
                std::string line = lstring->get(j);
                StringList* elements = this->split_string(line, ',');
                ss_X x = elements->get(0);
                ss_Y y = elements->get(1);
                ShareTuple st(x, y);
                tl->add(st);
            }
            // close file
            in_file->close();
            delete in_file;
        }

        // step 2 - join the shares
        // TODO
        TupleList* l = new TupleList();
        ShareTuple st("0", "m");
        l->add(st);
        // ------
        this->dealer->join(l);
        l->remove();

        // cleanup
        delete this->dealer;
    }
}

bool Controller::set_value(const char* arg, const char* value) {

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
        // p value
        case 'p': {
            this->set_p(value);
            break;
        }
        // dealer type value
        case 'd': {
            this->set_dealer_type(value);
            break;
        }
        default:
            std::cerr << "[Controller] Invalid option: " << arg << "\n";
            return false;
            break;
    }
    return true;
}

void Controller::set_t(const char* value) {
    std::string v(value);
    try {
        this->_t = std::stoul(v);
    } catch (const std::invalid_argument& ia) {
         std::cerr << "[Controller] Invalid argument on t definition\n";
    }
}

void Controller::set_n(const char* value) {
    std::string v(value);
    try {
        this->_n = std::stoul(v);
    } catch (const std::invalid_argument& ia) {
         std::cerr << "[Controller] Invalid argument on n definition\n";
    }
}

void Controller::set_p(const char* value) {
    std::string v(value);
    try {
        this->_p = std::stoul(v);
    } catch (const std::invalid_argument& ia) {
         std::cerr << "[Controller] Invalid argument on p definition\n";
    }
}

void Controller::set_file_path(const char* value) {
    this->_file_path = value;
}

bool Controller::set_list_filepath(const char** value, int index, int size) {
    this->_list_file_path = new StringList();
    for(int i = index+1; i < index+size; i++) {
        if (value[i][0] == '-') {
            delete this->_list_file_path;
            return false;
        }
        std::string file_path = value[i];
        this->_list_file_path->add(file_path);
    }
    return true;
}

void Controller::set_dealer_type(const char* value) {
    this->dealer_type = value;
}

void Controller::print_help() {
    std::cout << "sshared lib help information: \n";
    std::cout << "Usage:\n";
    std::cout << "./sshared (<operation> <args>)|(-h)\n";
    std::cout << "  operation: the operation that will be performed\n";
    std::cout << "      - split\n";
    std::cout << "      - join\n";
    std::cout << "  arguments: each argument must be followed by respective value\n";
    std::cout << "      - i: input file\n";
    std::cout << "      - t: minimum shares\n";
    std::cout << "      - n: number of shares\n";
    std::cout << "      - d: dealer type(shamir default)\n";
    std::cout << "      - p: prime number used(29**CHANGE THIS** default)\n";
    std::cout << "      - h: help information\n";
}
