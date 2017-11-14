/* test header include */
#include "main_test.h"

/* controller tests */
void test_controller(int argc, char* argv[]) {

    // controler test
    std::string buf;
    Controller* con = new Controller();

    bool check = true;
    // TEST: filter_message
    printf("  filter_message...");
    check = con->filter_message(argv, argc);
    if(!check) {
        printf("Error on filter message\n");
        return;
    }

    printf("Ok\n");

    /* output test
    buf = con->print_information();
    printf("%s\n", buf.c_str());
    */

    // cleanup
    delete con;
}

