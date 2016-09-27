#include "driver.hpp"

Driver::Driver(const std::string& filename, ParserBase *p)
    : infile_(filename), parser_(p) {
    p->ReadIn(filename);
}

Driver::Driver(Driver&& other)
    : infile_(other.infile_), parser_(other.parser_) {
    other.parser_ = nullptr;
}

Driver& Driver::operator=(Driver&& other) {
    if (this != &other) {
        infile_.swap(other.infile_);
        parser_ = other.parser_, other.parser_ = nullptr;
    }
    return *this;
}

Driver::~Driver() {
    infile_.empty();
    parser_ = nullptr;
}

void Driver::Reload(ParserBase *newp) {
    parser_ = newp;
}
