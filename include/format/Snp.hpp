#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Snp {

};

template < >
struct FormatReader<Snp> {
    std::vector<Snp> Read(const char *file) {

    }
};

template < >
struct FormatConverter<Snp> {
    void Parse(const std::vector<Snp>& data) {

    }
};

