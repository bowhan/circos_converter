#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Scatter {

};

template < >
struct FormatReader<Scatter> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Scatter> {
    void Parse(const std::vector<Scatter>& data) {

    }
};

