/* main tests include */
#include "main_test.h"

// main test function
int main(int argc, char* argv[]) {

    printf("[test] controller... \n");
    test_controller(argc, argv);

    printf("\n");
    printf("[test] shamir dealer... \n");
    test_shamir_dealer();

    printf("\n");
    printf("[test] file... \n");
    test_file();

    printf("\n");
    printf("[test] list... \n");
    test_list();
    
    return 0;
}
