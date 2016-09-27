#pragma once

#include "policy.hpp"
#include <string>
#include <vector>

class Snp {

};

template < >
struct FormatReader<Snp> {
    void Read(const std::string& file) {

    }
};

template < >
struct FormatParser<Snp> {
    void Parse(const std::vector<Snp>& data) {

    }
};

