#include "format/Scatter.hpp"

std::vector<Scatter> FormatReader<Scatter>::Read(const char *file) {
    FILE *in = fopen(file, "r");
    if (!in) {
        Error("cannot open input file");
    }
    std::vector<Scatter> ret;
    char buffer[1024];
    char chr[64];
    char name[64];
    char des[64];
    long long start, end;
    int count;
    while (fgets(buffer, 1024, in) != NULL) {
        if (buffer[0] == '#') continue;
        if ((count = sscanf(buffer, "%s\t%lld\t%lld\t%s\t%[^\n]", chr, &start, &end, name, des)) == 5) {
            ret.emplace_back(chr, start, end, name, des);
        }
    }
    return ret;
}


void FormatConverter<Scatter>::Parse(const std::vector<Scatter>& data) {
    printf("var SCATTER = [ \"SCATTER\", {\n");
    printf("\tSCATTERRadius: 220,\n");
    printf("\tinnerCircleSize: 1,\n");
    printf("\touterCircleSize: 7,\n");
    printf("\tinnerCircleColor: \"red\",\n");
    printf("\touterCircleColor: \"#CC3399\",\n");
    printf("\tinnerPointType: \"circle\",\n");
    printf("\touterPointType: \"circle\",\n");
    printf("\tinnerrectWidth: 2,\n");
    printf("\tinnerrectHeight: 2,\n");
    printf("\touterrectWidth: 10,\n");
    printf("\touterrectHeight: 10,\n");
    printf("\touterCircleOpacity: 1,\n");
    printf("\trandom_data: 0,\n");
    printf("}, [\n");
    for (const auto& scatter: data) {
        printf("\t{chr: \"%s\", start: \"%lld\", end: \"%lld\", name: \"%s\", des: \"%s\"},\n"
               , scatter.chr_.c_str()
               , scatter.start_
               , scatter.end_
               , scatter.name_.c_str()
               , scatter.des_.c_str()
        );
    }
    printf("]];");
}