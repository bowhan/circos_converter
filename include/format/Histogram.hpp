#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Histogram {

};

template < >
struct FormatReader<Histogram> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Histogram> {
    void Parse(const std::vector<Histogram>& data) {

    }
};

