#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Heatmap {

};

template < >
struct FormatReader<Heatmap> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Heatmap> {
    void Parse(const std::vector<Heatmap>& data) {

    }
};

