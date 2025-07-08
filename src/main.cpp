#include <iostream>
#include <cstdlib>
#include "modules.hpp"

int main(int argc, char ** argv) {
    const int limit = 10;

    IO io;
    Histogram histogram(limit);

    io.readFromStdIn(histogram);
    io.printToStdOut(histogram);

    return EXIT_SUCCESS;
}
