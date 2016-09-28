#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Cnv {

};

template < >
struct FormatReader<Cnv> {
    std::vector<Cnv> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Cnv> {
    void Parse(const std::vector<Cnv>& data) {

    }
};

