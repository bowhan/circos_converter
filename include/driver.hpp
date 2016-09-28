#pragma once

#include "parser.hpp"
#include <memory>

class Driver {
private:
    ParserBase *parser_ = nullptr;
    std::string infile_;
    using self = Driver;

    Driver(const Driver&);

    Driver& operator=(const Driver& other);

public:
    Driver(const std::string&, ParserBase *);

    Driver(Driver&&);

    Driver& operator=(Driver&& other);

    ~Driver();

    void Reload(ParserBase *);

    self& Read() {
        if (parser_ == nullptr) {
            throw std::runtime_error("Driver has not been loaded with any parser");
        }
        parser_->ReadIn(infile_.c_str());
        return *this;
    }

    self& Parse() {
        if (parser_ == nullptr) {
            throw std::runtime_error("Driver has not been loaded with any parser");
        }
        parser_->Parse();
        return *this;
    }
};

