#pragma once

#include "policy.hpp"
#include "utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Histogram {
    long long start_, end_;
    double value_;
    std::string chr_;
    //    std::string name_;

    Histogram(char *chr, long long int start, long long int anEnd, double value)
        : chr_(chr), start_(start), end_(anEnd), value_(value) {}
};

template < >
struct FormatReader<Histogram> {
    std::vector<Histogram> Read(const char *file);
};

template < >
struct FormatConverter<Histogram> {
    void Parse(const std::vector<Histogram>& data);
};

