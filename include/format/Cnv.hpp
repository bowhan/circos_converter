#pragma once

#include "policy.hpp"
#include "bolib/utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Cnv {
    long long start_;
    long long end_;
    double value_;
    std::string chr_;

    Cnv(char *c, long long s, long long e, double v)
        : chr_(c), start_(s), end_(e), value_(v) {}
};

template < >
struct FormatReader<Cnv> {
    std::vector<Cnv> Read(const char *file);
};

template < >
struct FormatConverter<Cnv> {
    void Parse(const std::vector<Cnv>& data);
};

