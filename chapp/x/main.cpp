#include "parameters.h"

#include <map>

#include <string>
#include <iostream>


int main(int argc, char *argv[]) {

    auto p = parameters(argc, argv);

    for (auto v : p)
        std::cout << v.first << " :: " << v.second << std::endl;

    return 0;
}