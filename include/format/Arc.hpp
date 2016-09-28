#pragma once

#include "policy.hpp"
#include "bolib/utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Arc {
    long long start_;
    long long end_;
    std::string chr_;
    std::string color_;
    std::string desc_;

    Arc(char *c, long long s, long long e, char *color, char *desc)
        : chr_(c), start_(s), end_(e), color_(color), desc_(desc) {}
};

template < >
struct FormatReader<Arc> {
    std::vector<Arc> Read(const char *filename);
};

template < >
struct FormatConverter<Arc> {
    void Parse(const std::vector<Arc>& data);
};
