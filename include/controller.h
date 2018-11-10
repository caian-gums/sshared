#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

// Util
#include "list.h"

// Dealers
#include "shamir_dealer.h"

// File Handler
#include "file_handler.h"

// Used in error log
#include <iostream>

namespace SS
{
    // List of Evaluated Shares as TupleLists
    typedef List<TupleList*> EvaluatedShares;
    
    class Controller {
    public:

        Controller() {
            this->_n = 0;
            this->_t = 0;
            this->_p = 0;
            this->_dealer_type = "shamir";
        }

        ~Controller() {
            if(!!this->_list_file_path) delete this->_list_file_path;
        }

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
        unsigned long _n;
        unsigned long _t;
        unsigned long _p;
        std::string _file_path;
        std::string _out_file_path;
        StringList* _list_file_path;
        // Dealer type
        std::string _dealer_type;
        // Dealer Object
        Dealer* _dealer;
        // EvaluatedShares of Shares
        EvaluatedShares* _es;


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
}
#endif
