#include <cstdlib>
#include <iostream>
#include "utils/kernel_color.hpp"
#include "utils/log.hpp"


void Warning(const std::string& s) {
    std::cerr << KERNAL_BOLDMAGENTA << "[Warning] " << s << KERNAL_RESET << std::endl;
}

void Error(const std::string& s) {
    std::cerr << KERNAL_BOLDRED << "[Error] " << s << KERNAL_RESET << std::endl;
    exit(1);
}

void Warning(const char* s) {
    fprintf(stderr, KERNAL_BOLDMAGENTA "[Warning] %s " KERNAL_RESET "\n", s);
}

void Error(const char* s) {
    fprintf(stderr, KERNAL_BOLDRED "[Error] %s " KERNAL_RESET "\n", s);
    exit(1);
}