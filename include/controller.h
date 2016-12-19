#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <stdio.h>
 
class Controller {
public:

    Controller() { }
    ~Controller() { }

    std::string filter_message(char* mes[], int size);

private:
    void call_function();

};
 
#endif
