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

    Controller() {
        this->_p = 0;
        this->_dealer_type = "shamir";
    }
    ~Controller();

    /* filter_message filter the recieved message from input
     * program
     * 
     *  @param  mes[]       list of parameters
     *  @param  size        list size
     *
     *  @return true on success or false on fail
     */
    bool filter_message(const char* mes[], int size);

private:
    unsigned long _n = 0;
    unsigned long _t = 0;
    unsigned long _p = 0;
    std::string _file_path;
    std::string _out_file_path;
    StringList* _list_file_path;
    // Dealer type
    std::string _dealer_type;
    // Dealer Object
    Dealer* _dealer;
    // EvaluetedShares of Shares
    EvaluetedShares* _es;


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

    /** Split a string based on a delimiter and returns a StringList*
     *
     *  @param  data        std::string to be splited
     *  @param  delimiter   character to be used as delimiter on split
     *
     *  @return StringList* with splited std::strings
     */
    StringList* split_string(std::string data, char delimiter);

    /** Write a content inside a file
     *
     *  @param  content     std::string to be written
     *  @param  to          filepath of the file
     *
     *  @return void
     */
    void write(std::string content, std::string to);

    /** Read a file and place the content inside a std::string
     *
     *  @param  from        filepath of the file
     *
     *  @return std::string with the content of the file
     */
    std::string read(std::string from);

    /** Split a content as std::string
     *
     *  @return void
     */
    void split();

    /** Join a content as std::string
     *
     *  @return void
     */
    void join();

};
 
#endif
