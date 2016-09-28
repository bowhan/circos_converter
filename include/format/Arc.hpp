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
    std::vector<Arc> Read(const char *filename) {
        FILE *in = fopen(filename, "r");
        if (in == NULL) {
            Error("cannot open input file");
        }
        std::vector<Arc> ret;
        char chr[64];
        char color[64];
        char desc[128];
        long long start, end;
        int count;
        while ((count = fscanf(in, "%s\t%lld\t%lld\t%s\t%s\n", chr, &start, &end, color, desc)) == 5) {
            ret.emplace_back(chr, start, end, color, desc);
        }
        return ret;
    }
};

template < >
struct FormatConverter<Arc> {
    void Parse(const std::vector<Arc>& data) {
        printf("var ARC = [ \"ARC\", {\n");
        printf("\tinnerRadius: -55,\n");
        printf("\touterRadius: -45,\n");
        printf("}, [\n");
        for (const auto& arc: data) {
            printf("\t{char: \"%s\", start: \"%lld\", end: \"%lld\", color: \"%s\", des: \"%s\"},\n"
                   , arc.chr_.c_str()
                   , arc.start_
                   , arc.end_
                   , arc.color_.c_str()
                   , arc.desc_.c_str());
        }
        printf("]];");
    }
};
