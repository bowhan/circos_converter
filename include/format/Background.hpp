#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Background {

};

template < >
struct FormatReader<Background> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Background> {
    void Parse(const std::vector<Background>& data) {

    }
};

