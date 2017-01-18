#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <stdio.h>

// Used in error log
#include <iostream>
 
class Controller {
public:

    Controller();
    ~Controller() { }

    /* filter_message filter the recieved message from input
     * program.
     * 
     *  @param  mes[]       list of parameters
     *  @param  size        list size
     *
     *  @return true on success or false on fail
     */
    bool filter_message(char* mes[], int size);

    // test method
    std::string print_information();

private:
    // attributes
    int n;
    int t;
    std::string file_path;

    // methods
    /* set_value is a general setting value to filer_message.
     * 
     *  @param  art         argument name
     *  @param  value       argument valeu
     *
     *  @return true if all goes ok, false on error.
     */
    bool set_value(char* arg, char* value);

    // inside set's
    void set_t(char* value);
    void set_n(char* value);
    void set_file_path(char* value);

    // print help information
    void print_help();

    // split/join functions
    void split();
    void join();

};
 
#endif
