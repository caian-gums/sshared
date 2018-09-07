/* main tests include */
#include "main_test.h"

/* file tests */
void test_file() {

    // file name
    std::string fp = "test.txt";

    // writable file
    WritableFile* wf = new WritableFile(fp);
    wf->open();
    std::string wfbuf = "Test file.\n1 2 3 test";
    wf->write(wfbuf);
    wf->close();
    delete wf;

    // readable file
    ReadableFile* rf = new ReadableFile(fp);
    rf->open();
    std::string rfbuf = rf->read();
    rf->close();
    delete rf;

    /* See the files:
    printf("wfbuf: '%s'\nrfbuf: '%s'\n", wfbuf.c_str(), rfbuf.c_str());
    */

    bool check = true;
    // TEST: compare test
    printf("  compare files test...");
    if(rfbuf.compare(wfbuf) == 0) check = true;
    else check = false;
    if(!check) {
        printf("Error on compare\n");
        return;
    }

    printf("Ok\n");
    
}
