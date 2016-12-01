#pragma once

#include <string>
#include <map>
#include "utils/log.hpp"

class SubProgram {
public:
    using subfunc = int (*)(int, char**);

    using name_mapper = std::map<std::string, subfunc>;
private:
    name_mapper subprograms_;
public:
    void Register(const std::string& name, subfunc f) {
        subprograms_[name] = f;
    }

    auto Call(const std::string& name, int argc, char** argv) {
        auto found = subprograms_.find(name);
        if (found == subprograms_.end()) {
            Error("unknown subprogram");
        }
        return found->second(argc, argv);
    }

};