#pragma once

#include <string>
#include <vector>

template <class T>
struct FormatReader {
    std::vector<T> Read(const char*);
};


template <class T>
struct FormatConverter {
    void Parse(const std::vector<T>& data);
};
