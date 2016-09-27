#pragma once

#include "policy.hpp"
#include <fstream>
#include <vector>

class ParserBase {
public:
    virtual void ReadIn(const std::string& infile) = 0;

    virtual void Parse() = 0;
};


template <class F>
class Parser
    : private FormatReader<F>
      , private FormatParser<F>
      , public ParserBase {
protected:
    using data_type = F;
    std::vector<data_type> data_;

    using ReaderPolicy = FormatReader<F>;
    using ParserPolicy = FormatParser<F>;

public:

    virtual void ReadIn(const std::string& infile) override;

    virtual void Parse() override;

};


template <class F>
void Parser<F>::ReadIn(const std::string& infile) {
    ReaderPolicy::Read(infile);
}

template <class F>
void Parser<F>::Parse() {
    ParserPolicy::Parse(data_);
}
