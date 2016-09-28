#pragma once

#include "policy.hpp"
#include "bolib/utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Snp {
    long long pos_;
    double value_;
    std::string chr_;
    std::string name_;

    static const char *const default_color;

    Snp(char *chr, long long pos, double value, char *name)
        : pos_(pos), value_(value), chr_(chr), name_(name) {}
};


template < >
struct FormatReader<Snp> {
    std::vector<Snp> Read(const char *file);
};

template < >
struct FormatConverter<Snp> {
    void Parse(const std::vector<Snp>& data);
};

