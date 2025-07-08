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
1. Navigate to the `cpp/` directory:
   ```sh
   cd cpp
   ```
2. Build the project using `make`:
   ```sh
   make
   ```
   This will produce the `histogram` binary in the `cpp/` directory.

### Run Example
To run the C++ histogram with an example input:
```sh
./histogram < input/mock01.txt
```

## Python Implementation

### Setup
1. Install dependencies (requires Python 3):
   ```sh
   pip install -r python/requirements.txt
   ```

### Run Example
To run the Python histogram with an example input:
```sh
python3 python/pythogram.py < python/mock01.txt
```

## Notes
- Both implementations read integer values from standard input and print a histogram to the console.
- Example input files are provided in each implementation's directory.
- `.gitignore` files are present in each project to exclude build artifacts and cache files from version control.
