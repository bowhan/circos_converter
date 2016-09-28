#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Heatmap {

};

template < >
struct FormatReader<Heatmap> {
    std::vector<Heatmap> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Heatmap> {
    void Parse(const std::vector<Heatmap>& data) {

    }
};

