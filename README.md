# Histogram Console Application

This repository contains two implementations of a histogram console application:
- **C++ implementation** (in `cpp/`)
- **Python implementation** (in `python/`)

## Project Structure

```
histogram/
  cpp/         # C++ implementation
    src/      # C++ source files
    bin/      # Compiled object files
    input/    # Example input files
    Makefile  # Build instructions
    histogram # Compiled binary (after build)
  python/      # Python implementation
    pythogram.py   # Main Python script
    mock01.txt     # Example input file
    requirements.txt # Python dependencies
  README.md    # This file
```

## C++ Implementation

### Build Instructions
To build the project from the project root:
```sh
make -C cpp
```
This will produce the `histogram` binary in the `cpp/` directory.

### Run Example
To run the C++ histogram with an example input from the project root:
```sh
./cpp/histogram < cpp/input/mock01.txt
```

## Python Implementation

### Setup
To install dependencies (requires Python 3), run from the project root:
```sh
pip install -r python/requirements.txt
```

### Run Example
To run the Python histogram with an example input from the project root:
```sh
python3 python/pythogram.py < python/mock01.txt
```

To display a graphical plot using matplotlib, add the `-p` flag:
```sh
python3 python/pythogram.py -p < python/mock01.txt
```

- By default, the script prints the histogram to the console.
- The `-p` flag opens a matplotlib window with a graphical histogram.

## Notes
- Both implementations read integer values from standard input and print a histogram to the console.
- Example input files are provided in each implementation's directory.
- `.gitignore` files are present in each project to exclude build artifacts and cache files from version control.
