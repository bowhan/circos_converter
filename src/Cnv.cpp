#include "format/Cnv.hpp"

std::vector<Cnv> FormatReader<Cnv>::Read(const char *file) {
    FILE *in = fopen(file, "r");
    if (!in) {
        Error("cannot open input file");
    }
    std::vector<Cnv> ret;
    char buffer[1024];
    char chr[64];
    long long start, end;
    double value;
    int count;
    while (fgets(buffer, 1024, in) != NULL) {
        if (buffer[0] == '#') continue;
        if ((count = sscanf(buffer, "%s\t%lld\t%lld\t%lf\n", chr, &start, &end, &value)) == 4) {
            ret.emplace_back(chr, start, end, value);
        }
    }
    return ret;
}

void FormatConverter<Cnv>::Parse(const std::vector<Cnv>& data) {
    printf("var CNV = [ \"CNV\", {\n");
    printf("\tmaxRadius: 155,\n");
    printf("\tminRadius: 116,\n");
    printf("\tCNVwidth: 2,\n");
    printf("\tCNVColor: \"#4876FF\",\n");
    printf("}, [\n");
    for (const auto& cnv: data) {
        printf("\t{chr: \"%s\", start: \"%lld\", end: \"%lld\", value: \"%lf\"},\n"
               , cnv.chr_.c_str()
               , cnv.start_
               , cnv.end_
               , cnv.value_
        );
    }
    printf("]];");
}