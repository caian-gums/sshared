#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <sstream>

// Util
#include "list.h"

// Dealers
#include "shamir_dealer.h"

// Files
#include "readable_file.h"
#include "writable_file.h"

// Used in error log
#include <iostream>

// List of Evaluated Shares as TupleLists
typedef List<TupleList*> EvaluetedShares;
typedef List<std::string> StringList;
 
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
    bool filter_message(const char* mes[], int size);

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
    std::string _out_file_path;
    StringList* _list_file_path;
    // Dealer type
    std::string dealer_type;
    // Dealer Object
    Dealer* dealer;
    // EvaluetedShares of Shares
    EvaluetedShares* es;


    // methods
    /* set_value is a general setting value to filer_message.
     * 
     *  @param  art         argument name
     *  @param  value       argument value
     *
     *  @return true if all goes ok, false on error.
     */
    bool set_value(const char* arg, const char* value);

    // inside set's
    void set_t(const char* value);
    void set_n(const char* value);
    void set_p(const char* value);
    void set_file_path(const char* value);
    void set_out_file_path(const char* value);
    void set_dealer_type(const char* value);

    bool set_list_filepath(const char** arg, int index, int size);

    // print help information
    void print_help();

    // util function to split a string
    StringList* split_string(std::string data, char delimiter);
    // util function to write some string content into a file
    void write(std::string content, std::string to);
    // util function to read and conver to string from a file
    std::string read(std::string from);

    // split/join functions
    void split();
    void join();

};
 
#endif
