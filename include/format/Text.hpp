#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Text {

};

template < >
struct FormatReader<Text> {
    std::vector<Text> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Text> {
    void Parse(const std::vector<Text>& data) {

    }
};

