//
// STL includes
//

#include <map>

//
// Standard includes
//

#include <string>
#include <iostream>
#include <fstream>


//
// Prototypes
//

std::map<std::string, std::string> fetchJSON(std::string filename);
std::string trim(std::string inString);


//
// Function: parameters()
//

std::map<std::string, std::string> parameters(int argc, char *argv[]) {

    std::map<std::string, std::string> p;

    // Parameter 0 is always the program
    p["_EXECUTABLE"] = argv[0];

    std::string sw, pa;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            // We have a switch
            sw = &argv[i][1];

            // Its parameter is the next item if it
            // doesn't start with a -
            if ((i < (argc-1)) && (argv[i+1][0] != '-')) {
                pa = argv[i+1];
                i++;

                p[sw] = pa;
            }
            else {
                // Otherwise the switch is the
                // parameter
                p[sw] = "";
            }
        }
    }

    return p;
}



std::string trim(std::string inString) {
    std::string s;

    for (auto i = 0; i < inString.size(); i++) {
        auto c = inString.substr(i, 1).c_str();

        if (c[0] != 32)
            s += c;
    }

    return s;
}

