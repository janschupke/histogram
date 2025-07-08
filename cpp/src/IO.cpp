#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include "modules.hpp"

using std::ostringstream;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::out_of_range;
using std::invalid_argument;

void IO::parseLine(const string & line) const {
    string message = "Expecting integer.";

    if (line.length() == 0) {
        throw invalid_argument(message);
    }

    for (string::const_iterator it = line.begin(); it != line.end(); it++) {
        if (!isdigit(*it)) {
            throw invalid_argument(message);
        }
    }
}

int IO::calculateScaleUnit(const int max, const int lines) const {
    int scaleUnit = max / lines;

    // Values overflow, larger scale is needed.
    if (max % lines != 0) {
        scaleUnit++;
    }

    return scaleUnit;
}

void IO::readFromStdIn(Histogram & histogram, bool showInstructions) const {
    string line;
    int value;

    if (showInstructions) {
        cout << "Enter integer values within <1; " << histogram.getLimit() << ">" << endl;
        cout << "Finish the input by entering 0" << endl;
        cout << "Enter: ";
    }

    while (getline(cin, line)) {
        try {
            parseLine(line);
            value = atoi(line.c_str());

            // Done reading.
            if (value == 0) {
                break;
            }

            histogram.incrementQuantity(value);
        } catch (invalid_argument e) {
            cerr << e.what() << " Ignoring last input." << endl;
        } catch (out_of_range e) {
            cerr << e.what() << " Ignoring last input." << endl;
        }

        if (showInstructions) {
            cout << "Enter: ";
        }
    }
}

void IO::printToStdOut(const Histogram & histogram) const {
    const int lines = 10;
    // 2 extra lines for legend.
    string outputData[lines + 2];

    if (histogram.getMaxQuantity() == 0) {
        cout << "Histogram is empty, nothing to print." << endl;
        cout << "\t(And hystogram is dead...)" << endl;
        return;
    }

    const int scaleUnit = calculateScaleUnit(histogram.getMaxQuantity(), lines);

    // Create legend.
    outputData[0] = "\t   1   2   3   4   5   6   7   8   9  10  ";
    outputData[1] = "\t------------------------------------------";

    // Fill data lines.
    for (int i = 1; i <= lines; i++) {
        ostringstream oss;
        int valueThreshold = i * scaleUnit;

        oss << valueThreshold << "\t";
        for (int j = 1; j <= histogram.getLimit(); j++) {
            if (histogram.getQuantity(j) >= valueThreshold) {
                oss << "||##";
            } else {
                oss << "||  ";
            }
        }
        oss << "||";

        outputData[i + 1] = oss.str();
    }

    cout << "Printing the histogram (because hystograms aren't real):" << endl;

    // Final printout.
    for (int i = lines + 1; i >= 0; i--) {
        cout << outputData[i] << endl;
    }
}
