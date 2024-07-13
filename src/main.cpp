#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>

void help() {
    std::cout << "Help message" << std::endl;
}

int main(int argc, char* argv[]) {
    int CONVERT_TO_STIF = -1;
    std::string IN_PATH = "";
    std::string OUT_PATH = "";

    int option;

    if (argc < 2) {
        std::cerr << "ERROR: Invalid usage. `" << argv[0] << " --help` for more information." << std::endl;
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        help();
        return 0;
    }

    while ((option = getopt(argc, argv, "tfi:o:")) != -1) {
        switch (option) {
            case 't':
                if (CONVERT_TO_STIF == -1)
                    CONVERT_TO_STIF = 1;
                else {
                    std::cerr << "ERROR: Already specified a method flag." << std::endl;
                    return 1;
                }
                break;
            case 'f':
                if (CONVERT_TO_STIF == -1)
                    CONVERT_TO_STIF = 0;
                else {
                    std::cerr << "ERROR: lready specified a method flag." << std::endl;
                    return 1;
                }
                break;
            case 'i':
                IN_PATH = optarg;
                break;
            case 'o':
                OUT_PATH = optarg;
                break;
        }
    }

    if (CONVERT_TO_STIF == -1) {
        std::cerr << "ERROR: Did not specify a method flag." << std::endl;
        return 1;
    }

    if (IN_PATH == "") {
        std::cerr << "ERROR: Did not specify an input path" << std::endl;
        return 1;
    }

    if (OUT_PATH == "") {
        std::cerr << "ERROR: Did not specify an output path" << std::endl;
        return 1;
    }

    return 0;
}