/* main tests include */
#include "main_test.h"

/* list tests */
void test_list() {
    // SS::List creation
    SS::List<int>* il = new SS::List<int>();
    SS::List<std::string>* sl = new SS::List<std::string>();

    // TEST: add test
    bool check = true;
    std::cout << "  add test...";

    // int test
    int el0 = 3;
    int el1 = 5;
    int el2 = 7;
    il->add(el0);
    il->add(el1);
    il->add(el2);
    if(il->get(0) != el0) check = false;
    if(il->get(1) != el1) check = false;
    if(il->get(2) != el2) check = false;

    if(!check) {
        std::cout << "Error on int" << std::endl;
        delete il;
        delete sl;
        return;
    }

    // string test
    std::string se0 = "test0";
    std::string se1 = "test2";
    std::string se2 = "testtest";
    sl->add(se0);
    sl->add(se1);
    sl->add(se2);
    if(sl->get(0).compare(se0) != 0) check = false;
    if(sl->get(1).compare(se1) != 0) check = false;
    if(sl->get(2).compare(se2) != 0) check = false;

    if(!check) {
        std::cout << "Error on string" << std::endl;
        delete il;
        delete sl;
        return;
    }
    
    std::cout << "Ok" << std::endl;

    // TEST: get test
    std::cout << "  get test...";

    // int test
    if(il->get(0) != el0) check = false;
    if(il->get(1) != el1) check = false;
    if(il->get(2) != el2) check = false;

    if(!check) {
        std::cout << "Error on int" << std::endl;
        delete il;
        delete sl;
        return;
    }

    // string test
    if(sl->get(0).compare(se0) != 0) check = false;
    if(sl->get(1).compare(se1) != 0) check = false;
    if(sl->get(2).compare(se2) != 0) check = false;
    if(!check) {
        std::cout << "Error on string" << std::endl;
        delete il;
        delete sl;
        return;
    }

    std::cout << "Ok" << std::endl;
    
    // TEST: len test
    std::cout << "  len test...";

    // int test
    if(il->len() != 3) check = false;
    if(!check) {
        std::cout << "Error on int" << std::endl;
        delete il;
        delete sl;
        return;
    }

    // string test
    if(sl->len() != 3) check = false;
    if(!check) {
        std::cout << "Error on string" << std::endl;
        delete il;
        delete sl;
        return;
    }
    
    std::cout << "Ok" << std::endl;

    // TEST: remove test
    std::cout << "  remove test...";

    // int test
    il->remove();
    il->remove();
    il->remove();
    if(il->len() != 0) check = false;
    if(!check) {
        std::cout << "Error on int" << std::endl;
        delete il;
        delete sl;
        return;
    }

    // string test
    sl->remove();
    sl->remove();
    sl->remove();
    if(sl->len() != 0) check = false;
    if(!check) {
        std::cout << "Error on string" << std::endl;
        delete il;
        delete sl;
        return;
    }
    
    std::cout << "Ok" << std::endl;

    // cleanup
    delete il;
    delete sl;

    return;
}
