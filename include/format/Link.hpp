#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Link {

};

template < >
struct FormatReader<Link> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Link> {
    void Parse(const std::vector<Link>& data) {

    }
};

