#pragma once

#include "policy.hpp"
#include "utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Scatter {
    long long start_;
    long long end_;
    std::string chr_, name_, des_;

    Scatter(const std::string& chr
            , long long int start
            , long long End
            , const std::string& name
            , const std::string& des
           )
        : chr_(chr), start_(start), end_(End), name_(name), des_(des) {}
};

template < >
struct FormatReader<Scatter> {
    std::vector<Scatter> Read(const char *file);
};

template < >
struct FormatConverter<Scatter> {
    void Parse(const std::vector<Scatter>& data);
};

