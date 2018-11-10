#include "controller.h"

SS::Controller::~Controller() {
    if(!_dealer) delete _dealer;
}

bool SS::Controller::filter_message(const char* mes[], int size) {

    // initial check
    if(size < 2) {
        std::cerr << "[sshared] Error: Number of arguments incorrect. Use -h (help)" << std::endl;
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
        std::cerr << "[sshared] Error: Pass the operation (split or join). Use -h (help)" << std::endl;
        return false;
    }
    int nsize = size - 1;

    // check for number of arguments
    if(nsize % 2 == 0 || nsize < 2) {
        std::cerr << "[sshared] Error:  Number of arguments incorrect. Use -h (help)" << std::endl;
        return false;
    }

    // set values on Controller
    for(int i = 2; i < nsize; i += 2) {
        if(mes[i][1] == 'l') {
            if(!this->set_list_filepath(mes, i, size - i)) {
                std::cerr << "[sshared] Error: Number of arguments incorrect. Use -h (help)" << std::endl;
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

std::string SS::Controller::read(std::string from) {
    SS::ReadableFile* in_file = new SS::ReadableFile(from);
    in_file->open();
    std::string data = in_file->read();
    in_file->close();
    delete in_file;
    return data;
}

void SS::Controller::write(std::string content, std::string to) {
    SS::WritableFile* out_file = new SS::WritableFile(to);
    out_file->open();
    out_file->write(content);
    out_file->close();
    delete out_file;
}

void SS::Controller::split() {
    if(this->_dealer_type.empty()) {
        std::cerr << "[sshared] Error: No Dealer Type defined" << std::endl;
    }
    if(this->_dealer_type.compare("shamir") == 0) {
        // read file
        std::string data = this->read(this->_file_path);

        this->_dealer = new ShamirDealer(this->_p);
        this->_es = new EvaluetedShares();
        SS::TupleList* tl;

        // step 1 - split each byte
        for(unsigned int i = 0; i < data.length() - 1; i++) {
            tl = this->_dealer->split(data.substr(i, 1), this->_t, this->_n);
            this->_es->add(tl);
        }

        // step 2 - save to files 
        for(unsigned int i = 0; i < this->_n; i++) {
            std::string out_share = "";
            // write the Shares on each file
            for(unsigned int j = 0; j < this->_es->len(); j++) {
                tl = this->_es->get(j);
                SS::ShareTuple st = tl->get(i);
                out_share += st.first() + "," + st.second() + "\n";
            }

            std::string share_file_name = this->_file_path + ".share" + std::to_string(i);
            this->write(out_share, share_file_name);
        }

        // cleanup
        delete this->_es;
        delete this->_dealer;
        return;
    }
    std::cerr << "[sshared] Error: Dealer Type not supported" << std::endl;
}

SS::StringList* SS::Controller::split_string(std::string data, char delimiter) {
    std::stringstream ssdata(data);
    std::string token;
    SS::StringList* lstring = new SS::StringList();
    while(std::getline(ssdata, token, delimiter)) {
        lstring->add(token);
    }
    return lstring;
}

void SS::Controller::join() {
    if(this->_dealer_type.empty()) {
        std::cerr << "[sshared] Error: No Dealer Type defined" << std::endl;
    }
    if(this->_dealer_type.compare("shamir") == 0) {

        this->_es = new EvaluetedShares();

        // step 1 - open files and get the shares
        for(unsigned int i = 0; i < this->_list_file_path->len(); i++) {
            // read the shares
            std::string data = this->read(this->_list_file_path->get(i));

            SS::StringList* lstring = this->split_string(data, '\n');
            
            for(unsigned int j = 0; j < lstring->len(); j++) {
                SS::TupleList* tl;
                // check for tuples on es
                if(this->_es->len() == 0 || j >= this->_es->len()) {
                    tl = new SS::TupleList();
                    this->_es->add(tl);
                }
                tl = this->_es->get(j);
                // build the tuples
                std::string line = lstring->get(j);
                SS::StringList* elements = this->split_string(line, ',');
                SS::ss_X x = elements->get(0);
                SS::ss_Y y = elements->get(1);
                SS::ShareTuple st(x, y);
                tl->add(st);
            }
        }

        // step 2 - join the shares
        this->_dealer = new ShamirDealer(this->_p);
        std::string out = "";

        for(unsigned int i = 0; i < this->_es->len(); i++) {
            SS::TupleList* tl = this->_es->get(i);
            out += this->_dealer->join(tl);
        }

        this->write(out, this->_out_file_path);

        // cleanup
        delete this->_dealer;
        delete this->_es;
        return;
    }
    std::cerr << "[sshared] Error: Dealer Type not supported" << std::endl;
}

bool SS::Controller::set_value(const char* arg, const char* value) {

    if(arg[0] != '-') {
        std::cerr << "[ssshared] Error: Invalid argument passed: " << arg << std::endl;
        return false;
    }

    switch(arg[1]) {
        // input file path
        case 'i': {
            this->set_file_path(value);
            break;
        }
        // output file path
        case 'o': {
            this->set_out_file_path(value);
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
        // _dealer type value
        case 'd': {
            this->set_dealer_type(value);
            break;
        }
        default:
            std::cerr << "[sshared] Error: Invalid option: " << arg << std::endl;
            return false;
            break;
    }
    return true;
}

void SS::Controller::set_t(const char* value) {
    std::string v(value);
    try {
        this->_t = std::stoul(v);
    } catch (const std::invalid_argument& ia) {
         std::cerr << "[sshared] Error: Invalid argument on t definition" << std::endl;
    }
}

void SS::Controller::set_n(const char* value) {
    std::string v(value);
    try {
        this->_n = std::stoul(v);
    } catch (const std::invalid_argument& ia) {
         std::cerr << "[sshared] Error: Invalid argument on n definition" << std::endl;
    }
}

void SS::Controller::set_p(const char* value) {
    std::string v(value);
    try {
        this->_p = std::stoul(v);
    } catch (const std::invalid_argument& ia) {
         std::cerr << "[sshared] Error: Invalid argument on p definition" << std::endl;
    }
}

void SS::Controller::set_file_path(const char* value) {
    this->_file_path = value;
}

void SS::Controller::set_out_file_path(const char* value) {
    this->_out_file_path = value;
}

bool SS::Controller::set_list_filepath(const char** value, int index, int size) {
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

void SS::Controller::set_dealer_type(const char* value) {
    this->_dealer_type = value;
}

void SS::Controller::print_help() {
    std::cout << "sshared lib help information: " << std::endl;
    std::cout << "Usage:" << std::endl;
    std::cout << "./sshared (<operation> <args>)|(-h)" << std::endl;
    std::cout << "  operation: the operation that will be performed" << std::endl;
    std::cout << "      - split" << std::endl;
    std::cout << "      - join" << std::endl;
    std::cout << "  arguments: each argument must be followed by respective values" << std::endl;
    std::cout << "      - i: input file(for split)" << std::endl;
    std::cout << "      - l: list of input files(in case of join) -- must be the LAST argument with values" << std::endl;
    std::cout << "      - o: output file name(in case of join)" << std::endl;
    std::cout << "      - t: minimum shares" << std::endl;
    std::cout << "      - n: number of shares" << std::endl;
    std::cout << "      - d: dealer type(shamir default)" << std::endl;
    std::cout << "      - p: prime number used(29**CHANGE THIS** default)" << std::endl;
    std::cout << "      - h: help information" << std::endl;
}
