#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Scatter {

};

template < >
struct FormatReader<Scatter> {
    std::vector<Scatter> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Scatter> {
    void Parse(const std::vector<Scatter>& data) {

    }
};

