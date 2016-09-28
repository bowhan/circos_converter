#pragma once

#include "policy.hpp"
#include "bolib/utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Background {
};

template < >
struct FormatReader<Background> {
    std::vector<Background> Read(const char *file);
};

template < >
struct FormatConverter<Background> {
    void Parse(const std::vector<Background>& data);
};

