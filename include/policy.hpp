#pragma once

#include <string>
#include <vector>

template <class T>
struct FormatReader {
    void Read(const std::string&);
};


template <class T>
struct FormatParser {
    void Parse(const std::vector<T>& data);
};
