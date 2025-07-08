#ifndef HISTOGRAM_HPP
#define HISTOGRAM_HPP

/**
 * Histogram plot.
 */
class Histogram {
    private:
        /**
         * Amount of available values.
         */
        const int limit;

        /**
         * Array of quantities. Array index + 1 represents the measured value.
         */
        int * data;

    public:
        Histogram(int limit);
        ~Histogram();

        /**
         * Gets current quantity of the provided value.
         *
         * @param value
         * @return Current quantity.
         * @throws out_of_range If the value is not within <1; limit>.
         */
        int getQuantity(int value) const;

        /**
         * Gets the maximum quantity across all values.
         *
         * @return Max value.
         */
        int getMaxQuantity() const;

        /**
         * Get the histogram's limit of available values.
         *
         * @return Limit.
         */
        int getLimit() const;

        /**
         * Increases the quantity of provided value by one.
         *
         * @param Value to be increased.
         * @throws out_of_range If the value is not within <1; limit>.
         */
        void incrementQuantity(int value);

        /**
         * Decreases the quantity of provided value by one.
         *
         * @param Value to be decreased.
         * @throws out_of_range If the value is not within <1; limit>.
         */
        void decrementQuantity(int value);
};

#endif // HISTOGRAM_HPP
