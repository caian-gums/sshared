#include <iostream>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    int i = 0;
    std::string out;
    while(i < argc) {
        out += "argv[" + std::to_string(i) + "]: " + argv[i] + "\n";
        i++;
    }
    printf("argc: %d\n%s", argc, out.c_str());

    return 0;
}
