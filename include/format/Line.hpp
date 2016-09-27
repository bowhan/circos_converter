#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Line {

};

template < >
struct FormatReader<Line> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Line> {
    void Parse(const std::vector<Line>& data) {

    }
};

