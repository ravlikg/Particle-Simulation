#pragma once

#include <Random.hpp>
#include <random>

class Random {
public:
    static double getDouble(const double min, const double max) {
        std::uniform_real_distribution<double> distribution(min, max);
        return distribution(generator_);
    }

private:
    inline static std::mt19937 generator_{std::random_device{}()};

};