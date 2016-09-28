#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Link {

};

template < >
struct FormatReader<Link> {
    std::vector<Link> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Link> {
    void Parse(const std::vector<Link>& data) {

    }
};

