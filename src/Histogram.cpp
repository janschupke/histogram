#include <stdexcept>
#include "modules.hpp"

using std::out_of_range;

Histogram::Histogram(int limit) : limit(limit) {
    data = new int[limit];

    for (int i = 0; i < limit; i++) {
        data[i] = 0;
    }
}

Histogram::~Histogram() {
    delete [] data;
}

int Histogram::getQuantity(int value) const {
    if (value < 1 || value > limit) {
        throw out_of_range("Out of range.");
    }

    return data[value - 1];
}

int Histogram::getMaxQuantity() const {
    int max = 0;

    for (int i = 0; i < limit; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    return max;
}

int Histogram::getLimit() const {
    return limit;
}

void Histogram::incrementQuantity(int value) {
    if (value < 1 || value > limit) {
        throw out_of_range("Out of range.");
    }

    data[value - 1]++;
}

void Histogram::decrementQuantity(int value) {
    if (value < 1 || value > limit) {
        throw out_of_range("Out of range.");
    }

    data[value - 1]--;
}
