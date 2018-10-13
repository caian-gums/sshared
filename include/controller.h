#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

// Util
#include "list.h"

// Dealers
#include "shamir_dealer.h"


// Used in error log
#include <iostream>
 
class Controller {
public:

    Controller() {}
    ~Controller();

    /* filter_message filter the recieved message from input
     * program.
     * 
     *  @param  mes[]       list of parameters
     *  @param  size        list size
     *
     *  @return true on success or false on fail
     */
    bool filter_message(char* mes[], int size);

    friend std::ostream & operator<<(std::ostream & os, Controller c) {
        os << "Controller information: "
        << "\n  t = " << std::to_string(c._t)
        << "\n  n = " << std::to_string(c._n)
        << "\n  p = " << std::to_string(c._p)
        << "\n  _file_path = " << ((!c._file_path.empty()) ? c._file_path : "<No file provided>")
        << "\n  dealer type = " << ((!c.dealer_type.empty()) ? c.dealer_type : "shamir");
        return os;
    }

private:
    // attributes
    unsigned long _n = 0;
    unsigned long _t = 0;
    unsigned long _p = 0;
    std::string _file_path;
    // Dealer type
    std::string dealer_type;
    // Dealer Object
    Dealer* dealer;

    // methods
    /* set_value is a general setting value to filer_message.
     * 
     *  @param  art         argument name
     *  @param  value       argument value
     *
     *  @return true if all goes ok, false on error.
     */
    bool set_value(char* arg, char* value);

    // inside set's
    void set_t(char* value);
    void set_n(char* value);
    void set_p(char* value);
    void set_file_path(char* value);
    void set_dealer_type(char* value);

    // print help information
    void print_help();

    // split/join functions
    void split();
    void join();

};
 
#endif
