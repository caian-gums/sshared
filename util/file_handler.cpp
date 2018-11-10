#include "file_handler.h"


std::string SS::FileHandler::read(std::string from) {
    SS::ReadableFile* in_file = new SS::ReadableFile(from);
    in_file->open();
    std::string data = in_file->read();
    in_file->close();
    delete in_file;
    return data;
}

void SS::FileHandler::write(std::string content, std::string to) {
    SS::WritableFile* out_file = new SS::WritableFile(to);
    out_file->open();
    out_file->write(content);
    out_file->close();
    delete out_file;
}

SS::StringList* SS::FileHandler::split_string(std::string data, char delimiter) {
    std::stringstream ssdata(data);
    std::string token;
    SS::StringList* lstring = new SS::StringList();
    while(std::getline(ssdata, token, delimiter)) {
        lstring->add(token);
    }
    return lstring;
}