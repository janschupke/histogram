#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include "modules.hpp"

using std::string;

/**
 * Handles all IO operations.
 */
class IO {
    private:
        /**
         * Parses one input line.
         *
         * @param line Provided line.
         * @throws invalid_argument If the line is empty or doesn't represent an integer value.
         */
        void parseLine(const string & line) const;

        /**
         * Calculates output scale unit based on maximum quantity and requested number of lines.
         *
         * @param max Maximum quantity across all histogram's values.
         * @param lines Requested number of lines for output.
         * @return Scale unit for one output line.
         */
        int calculateScaleUnit(const int max, const int lines) const;

    public:
        /**
         * Reads data from standard input and saves them into the histogram instance.
         *
         * @param histogram Provided Histogram instance that is being modified by the input.
         */
        void readFromStdIn(Histogram & histogram) const;

        /**
         * Prints the current state of the provided histogram to the standard output.
         *
         * @param histogram Histogram instance to be printed out.
         */
        void printToStdOut(const Histogram & histogram) const;
};

#endif // IO_HPP
