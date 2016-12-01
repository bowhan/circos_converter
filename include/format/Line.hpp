#pragma once

#include "policy.hpp"
#include "utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Line {
    long long pos_;
    double value_;
    std::string chr_;

    Line(char *c, long long p, double v)
        : chr_(c), pos_(p), value_(v) {}
};

template < >
struct FormatReader<Line> {
    std::vector<Line> Read(const char *file);
};

template < >
struct FormatConverter<Line> {
    void Parse(const std::vector<Line>& data);
};

