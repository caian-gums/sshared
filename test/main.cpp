/* main tests include */
#include "main_test.h"

// main test function
int main(int argc, char* argv[]) {

    // std::cout <<"[test] controller... " << std::endl;
    // test_controller(argc, argv);

    //std::cout << std::endl;
    std::cout << "[test] shamir dealer... " << std::endl;
    test_shamir_dealer();

    std::cout << std::endl;
    std::cout << "[test] file... " << std::endl;
    test_file();

    std::cout << std::endl;
    std::cout << "[test] list... " << std::endl;
    test_list();

    return 0;
}
