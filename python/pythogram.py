#!/usr/bin/python2

import sys
import getopt
from matplotlib import pyplot as plt

class Histogram:
    """ Histogram plot. """

    def __init__(self, limit):
        self._limit = limit
        self._data = [0] * limit

    def get_quantity(self, value):
        if value < 1 or value > self._limit:
            raise IndexError("Out of bounds. Ignoring last input.")
        return self._data[value - 1]

    def get_max_quantity(self):
        return max(self._data)

    def get_limit(self):
        return self._limit

    def increment_quantity(self, value):
        if value < 1 or value > self._limit:
            raise IndexError("Out of bounds. Ignoring last input.")
        self._data[value - 1] += 1


class IO:
    """ Handles all I/O operations. """

    def read_from_stdin(self, histogram):
        """ Reads data from user input and puts them into the histogram. """

        print("Enter integer values within <1; {0}>".format(histogram.get_limit()))
        print("Finish the input by entering 0")

        while True:
            try:
                line = input("Enter: ")
            except EOFError:
                break

            try:
                value = int(line)
            except ValueError:
                print("Expecting integer. Ignoring last input.")
                continue

            # Reading is done.
            if value == 0:
                break

            histogram.increment_quantity(value)

    def read_from_file(self, filename, histogram):
        """ Reads data from the input file and puts them into the histogram. """

        with open(filename) as f:
            for line in f.readlines():
                try:
                    value = int(line)
                    histogram.increment_quantity(value)
                except ValueError:
                    print("Expecting integer. Aborting input.")
                    break

    def _calculate_scale_unit(self, maximum, lines):
        """ Calculates the amount by which each line threshold is increased. """

        scale_unit = int(maximum / lines)
        # Values overflow, larger scale is needed.
        if maximum % lines != 0:
            scale_unit += 1
        return scale_unit

    def _make_legend(self, limit):
        numbers = "\t   "
        border = "\t---"

        for i in range(1, limit + 1):
            # TODO: sucks for limit > 99
            if i < 9:
                numbers += "{0}   ".format(i)
            else:
                numbers += "{0}  ".format(i)
            border += "----"

        return numbers, border

    def _populate_line(self, histogram, threshold):
            line = "{0}\t".format(threshold)

            # Fill in bars to the needed height.
            for i in range(1, histogram.get_limit() + 1):
                if histogram.get_quantity(i) >= threshold:
                    line += "||##"
                else:
                    line += "||  "

            line += "||"
            return line

    def print_to_stdout(self, histogram, lines):
        """ Makes the histogram's data pretty as a picture, for the printout.

        It does kind of make a picture out of them...
        """

        if histogram.get_max_quantity() == 0:
            print("Histogram is empty, nothing to print.")
            print("\t(And hystogram is dead...)")
            return

        scale_unit = self._calculate_scale_unit(histogram.get_max_quantity(), lines)
        output_data = [""] * (lines + 2)
        output_data[0], output_data[1] = self._make_legend(histogram.get_limit())

        # Populate output lines with data.
        for i in range(1, lines + 1):
            threshold = i * scale_unit
            output_data[i + 1] = self._populate_line(histogram, threshold)

        # Final printout. Dat -1...
        print("Printing the histogram (because hystograms aren't real):")
        for i in range(lines + 1, -1, -1):
            print(output_data[i])

    def show_plot(self, histogram):
        if histogram.get_max_quantity() == 0:
            return

        x = range(1, histogram.get_limit() + 1)
        y = [0] * histogram.get_limit()
        for i in range(0, histogram.get_limit()):
            y[i] = histogram.get_quantity(i + 1)

        plt.bar(x, y, color='#008800', width=1, align='center')
        plt.title("Hyyyyystogram")
        plt.xlabel("Values")
        plt.ylabel("Quantity")
        plt.show()


class Config:
    """ Holds configuration values and provides parameter parsing. """

    def __init__(self):
        self.lines = 10
        self.limit = 10
        self.input_filename = None
        self.plot = False

    def show_help(self):
        print("""
            Usage: histogram [-p] [-r N] [-l N] [-i F]
            \tp: Toggles graphical plotting.
            \tr: Sets the amount of text output rows.
            \tl: Sets the maximum value on the X axis.
            \ti: Specifies an input file instead of the standard input.
            """)

    def parse_arguments(self, argv):
        try:
            opts, args = getopt.getopt(argv, "pr:l:i:h")
        except getopt.GetoptError as e:
            print(str(e))
            self.show_help()
            sys.exit(2)

        for o, a in opts:
            if o == "-p":
                self.plot = True
            elif o == "-r":
                try:
                    self.lines = int(a)
                except ValueError:
                    print("Expecting numeric value for -r.")
                    sys.exit(1)
            elif o == "-l":
                try:
                    self.limit = int(a)
                except ValueError:
                    print("Expecting numeric value for -l.")
                    sys.exit(1)
            elif o == "-i":
                self.input_filename = a
            elif o == "-h":
                self.show_help()
                sys.exit(0)
            else:
                self.show_help()


def main():
    config = Config()
    config.parse_arguments(sys.argv[1:])

    histogram = Histogram(config.limit)
    io = IO()

    if config.input_filename is None:
        io.read_from_stdin(histogram)
    else:
        io.read_from_file(config.input_filename, histogram)

    io.print_to_stdout(histogram, config.lines)
    if config.plot:
        io.show_plot(histogram)

if __name__ == "__main__":
    main()
