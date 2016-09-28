#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Histogram {

};

template < >
struct FormatReader<Histogram> {
    std::vector<Histogram> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Histogram> {
    void Parse(const std::vector<Histogram>& data) {

    }
};

