/* main tests include */
#include "main_test.h"

/* file tests */
void test_file() {

    // file name
    std::string fp = "test.txt";

    // writable file
    SS::WritableFile* wf = new SS::WritableFile(fp);
    wf->open();
    std::string wfbuf = "Test file.\n1 2 3 test";
    wf->write(wfbuf);
    wf->close();
    delete wf;

    // readable file
    SS::ReadableFile* rf = new SS::ReadableFile(fp);
    rf->open();
    std::string rfbuf = rf->read();
    rf->close();
    delete rf;

    bool check = true;
    // TEST: compare test
    std::cout << "  compare files test...";
    if(rfbuf.compare(wfbuf) == 0) check = true;
    else check = false;
    if(!check) {
        std::cout << "\nError on compare" << std::endl;
        return;
    }

    std::cout << "Ok" << std::endl;
    
}
