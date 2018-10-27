/* test header include */
#include "main_test.h"

static const int argc_error = 1;
static const char* argv_error[argc_error] = {""};

static const int argc_split = 10;
static const char* argv_split[argc_split] = {
    "sshare",
    "split",
    "-i",
    "sample2.txt",
    "-t",
    "3",
    "-n",
    "5",
    "-p",
    "104471"
};

static const int argc_join = 12;
static const char* argv_join[argc_join] = {
    "sshare",
    "join",
    "-p",
    "104471",
    "-o",
    "out_sample.txt",
    "-l",
    "sample2.txt.share0",
    "sample2.txt.share1",
    "sample2.txt.share2",
    "sample2.txt.share3",
    "sample2.txt.share4"
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
    delete con;
    con = new Controller();

    std::cout << "    split call...";
    check = con->filter_message(argv_split, argc_split);
    if(!check) {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << "Ok" << std::endl;
    }
    delete con;
    con = new Controller();

    std::cout << "    join call...";
    check = con->filter_message(argv_join, argc_join);
    if(!check) {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << "Ok" << std::endl;
    }

    // cleanup
    delete con;
}

/* controller tests */
void test_controller() {

    test_filter_message();

}

