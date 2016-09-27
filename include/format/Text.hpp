#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Text {

};

template < >
struct FormatReader<Text> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Text> {
    void Parse(const std::vector<Text>& data) {

    }
};

