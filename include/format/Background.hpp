#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Background {

};

template < >
struct FormatReader<Background> {
    std::vector<Background> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Background> {
    void Parse(const std::vector<Background>& data) {

    }
};

