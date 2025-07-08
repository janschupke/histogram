#include <iostream>
#include <cstdlib>
#include "modules.hpp"
#include <unistd.h>

int main(int argc, char ** argv) {
    const int limit = 10;

    IO io;
    Histogram histogram(limit);

    // Check if input is from a terminal
    bool showInstructions = isatty(fileno(stdin));
    io.readFromStdIn(histogram, showInstructions);
    io.printToStdOut(histogram);

    return EXIT_SUCCESS;
}
