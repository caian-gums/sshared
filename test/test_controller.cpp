/* test header include */
#include "main_test.h"

/* controller tests */
void test_controller(int argc, char* argv[]) {

    // controler test
    std::string buf;
    Controller* con = new Controller();

    bool check = true;
    // TEST: filter_message
    std::cout << "  filter_message...";
    check = con->filter_message(argv, argc);
    if(!check) {
        std::cout << "Error on filter message" << std::endl;
        // cleanup
        delete con;
        return;
    }

    std::cout << "Ok" << std::endl;

    /* output test
    buf = con->print_information();
    std::cout << "buf" << std::endl;
    */

    // cleanup
    delete con;
}

