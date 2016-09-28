#include "format/Background.hpp"

std::vector<Background> FormatReader<Background>::Read(const char *file) {
    return std::vector<Background>{};
}

void FormatConverter<Background>::Parse(const std::vector<Background>& data) {
    printf("var BACKGROUND = [ \"BACKGROUND\" , {\n");
    printf("\tBginnerRadius: 205, \n");
    printf("\tBgouterRadius: 153, \n");
    printf("\tBgFillColor: \"#F2F2F2\", \n");
    printf("\tBgborderColor : \"#000\", \n");
    printf("\tBgborderSize : 0.3 \n");
    printf("}];\n");
}