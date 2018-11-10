#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <sstream>

#include "list.h"
#include "readable_file.h"
#include "writable_file.h"

namespace SS
{
    typedef List<std::string> StringList;

    class FileHandler {
    public:
        /** Split a string based on a delimiter and returns a StringList*
         *
         *  @param  data        std::string to be splited
         *  @param  delimiter   character to be used as delimiter on split
         *
         *  @return StringList* with splited std::strings
         */
        static StringList* split_string(std::string data, char delimiter);

        /** Write a content inside a file
         *
         *  @param  content     std::string to be written
         *  @param  to          filepath of the file
         *
         *  @return void
         */
        static void write(std::string content, std::string to);

        /** Read a file and place the content inside a std::string
         *
         *  @param  from        filepath of the file
         *
         *  @return std::string with the content of the file
         */
        static std::string read(std::string from);
    };
}
 
#endif
