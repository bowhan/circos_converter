#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Line {

};

template < >
struct FormatReader<Line> {
    std::vector<Line> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Line> {
    void Parse(const std::vector<Line>& data) {

    }
};

