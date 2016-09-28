#include "format/Text.hpp"

std::vector<Text> FormatReader<Text>::Read(const char *file) {
    std::vector<Text> ret;
    FILE *in = fopen(file, "r");
    if (!in) {
        Error("cannot open input file");
    }
    char line[1024];
    fscanf(in, "%[^\n]", line);
    ret.emplace_back(line);
    return ret;
}


void FormatConverter<Text>::Parse(const std::vector<Text>& data) {
    printf("var TEXT = [ \"TEXT\" , {\n");
    printf("\tx: -20, \n");
    printf("\ty: 0, \n");
    printf("\ttextSize: 20, \n");
    printf("\ttextWeight: \"bold\", \n");
    printf("\ttextColor: \"red\", \n");
    printf("\ttextOpacity: 1.0, \n");
    printf("\ttext: \"%s\", \n", data[0].name_.c_str());
    printf("}];");
}