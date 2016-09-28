#pragma once

#include "policy.hpp"
#include "bolib/utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Link {
    long long g1start, g1end;
    long long g2start, g2end;
    std::string name;
    std::string g1chr, g1name;
    std::string g2chr, g2name;

    Link(char *n
         , char *c1, long long s1, long long e1, char *n1
         , char *c2, long long s2, long long e2, char *n2
        )
        : name(n)
          , g1chr(c1), g1start(s1), g1end(e1), g1name(n1)
          , g2chr(c2), g2start(s2), g2end(e2), g2name(n2) {}
};

template < >
struct FormatReader<Link> {
    std::vector<Link> Read(const char *file);
};

template < >
struct FormatConverter<Link> {
    void Parse(const std::vector<Link>& data);
};

