#pragma once

#include "policy.hpp"
#include <fstream>
#include <vector>

class ParserBase {
public:
    virtual void ReadIn(const char *) = 0;

    virtual void Parse() = 0;
};


template <class F>
class Parser
    : private FormatReader<F>
      , private FormatConverter<F>
      , public ParserBase {
protected:
    using data_type = F;
    std::vector<data_type> data_;

    using ReaderPolicy = FormatReader<F>;
    using ParserPolicy = FormatConverter<F>;

public:

    virtual void ReadIn(const char *infile) override;

    virtual void Parse() override;

};


template <class F>
void Parser<F>::ReadIn(const char *infile) {
    data_ = ReaderPolicy::Read(infile);
}

template <class F>
void Parser<F>::Parse() {
    ParserPolicy::Parse(data_);
}
