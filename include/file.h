#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

class File {
public:

    File(std::string path) : fp(path) { }
    ~File() { }

    /* open method open a file with the given path on object creation
     *
     *  @return void.
     */
    void open();

    /* close method closes the file that was opened
     *
     *  @return void.
     */
    void close();

protected:
    // attributes
    // file path
    std::string fp;
    // file stream
    std::fstream fs;

};
 
#endif
