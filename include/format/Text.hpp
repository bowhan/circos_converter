#pragma once

#include "policy.hpp"
#include "utils/log.hpp"
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <vector>

struct Text {
    std::string name_;

    Text(char *n)
        : name_(n) {}
};

template < >
struct FormatReader<Text> {
    std::vector<Text> Read(const char *file);
};

template < >
struct FormatConverter<Text> {
    void Parse(const std::vector<Text>& data);
};

