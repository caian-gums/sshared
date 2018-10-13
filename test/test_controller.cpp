/* test header include */
#include "main_test.h"

static const int argc_error = 1;
static const char* argv_error[argc_error] = {""};

static const int argc_split = 10;
static const char* argv_split[argc_split] = {
    "sshare",
    "split",
    "-i",
    "sample.txt",
    "-t",
    "3",
    "-n",
    "5",
    "-p",
    "104471"
};

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

    std::cout << "    split call...";
    check = con->filter_message(argv_split, argc_split);
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

