/* test header include */
#include "main_test.h"

static const int argc_error = 1;
static char* argv_error[argc_error];

void test_filter_message() {

    std::cout << "  filter_message test";

    Controller* con = new Controller();
    bool check = true;

    std::cout << std::endl;
    std::cout << "    invalid call...";
    check = con->filter_message(argv_error, argc_error);
    if (check) {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << "Ok" << std::endl;
    }

    std::cout << "    correct call...";
    check = con->filter_message(argv_error, argc_error);
    if(!check) {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << "Ok" << std::endl;
    }

    // std::cout << con << std::endl;

    // cleanup
    delete con;
}

/* controller tests */
void test_controller() {

    test_filter_message();

}

