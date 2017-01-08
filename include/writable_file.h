#ifndef WRITABLEFILE_H
#define WRITABLEFILE_H

#include "file.h"

class WritableFile : public File {
public:

    WritableFile(std::string path) : File(path) { }
    ~WritableFile();

    /* write method writes a file with the given path on object creation
     *
     *  @param val      value to be written
     *
     *  @return void
     */
    void write(std::string val);

private:
    /* file_exist method check if a file exist. If not, create a file.
     * This method is useful on write files
     *
     *  @return true if file exists or false if doesn't.
     */
    bool file_exist();

    void file_create();

};
 
#endif
