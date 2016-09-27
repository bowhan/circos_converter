#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Arc {

};

template < >
struct FormatReader<Arc> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Arc> {
    void Parse(const std::vector<Arc>& data) {

    }
};

