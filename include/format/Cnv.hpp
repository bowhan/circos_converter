#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Cnv {

};

template < >
struct FormatReader<Cnv> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Cnv> {
    void Parse(const std::vector<Cnv>& data) {

    }
};

