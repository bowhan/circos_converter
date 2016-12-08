#pragma once

#include "policy.hpp"
#include "utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Heatmap {
    long long start_, end_;
    double value_;
    std::string chr_;
    std::string seq_;

    Heatmap(char *chr, long long int start, long long int anEnd, int num_reads, int num_mapper, std::string seq)
        : chr_(chr), start_(start), end_(anEnd), value_(double(num_reads) / num_mapper), seq_(seq) {}
};

template < >
struct FormatReader<Heatmap> {
    std::vector<Heatmap> Read(const char *file);
};

template < >
struct FormatConverter<Heatmap> {
    void Parse(const std::vector<Heatmap>& data);
};

