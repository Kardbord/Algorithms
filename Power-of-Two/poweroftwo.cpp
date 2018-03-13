#include <cstdlib>   // exit macros
#include <iostream>  // I/O stuff
#include <exception> // exception handling
#include <string>    // stol

// Determines if @num is a power of two
//
// Determines if @num is a power of two by taking
// advantage of the fact that any integer that is a power
// of two only has one bit flipped. 
// Hence, if (@num & @num - 1) == 0
// then @num is a power of two.
//
// param num : any integer
// return    : true if @num is a power of two, false if not
bool isPowerOfTwo(int64_t const & num) {
    return ((num & (num - 1)) == 0);
}

// Prints a helpful message :)
void printHelp() {
    std::cout << "Try running this program with an integer command "
              << "line input.\n"
              << "For example:\n\n"
              << "./thisprogram 2" << std::endl << std::endl << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "No command line arguments provided.\n";
        printHelp();
        return EXIT_FAILURE;
    }
    
    for (unsigned int i = 1; i < argc; ++i) {
        try {
            int64_t num = std::stol(argv[i]);

            if (isPowerOfTwo(num) && num != 0) {
                std::cout << num << " is a power of two\n";
            } else {
                std::cout << num << " is not a power of two\n";
            }
        }
        catch (std::exception) { /* do nothing */ }
    }

    return EXIT_SUCCESS;
}
