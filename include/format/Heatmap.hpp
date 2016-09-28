#pragma once

#include "policy.hpp"
#include "bolib/utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Heatmap {
    long long start_, end_;
    double value_;
    std::string chr_;
    std::string name_;

    Heatmap(char *chr, long long int start, long long int anEnd, char *name, double value)
        : chr_(chr), start_(start), end_(anEnd), value_(value), name_(name) {}
};

template < >
struct FormatReader<Heatmap> {
    std::vector<Heatmap> Read(const char *file);
};

template < >
struct FormatConverter<Heatmap> {
    void Parse(const std::vector<Heatmap>& data);
};

