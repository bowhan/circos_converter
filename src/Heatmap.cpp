#include "format/Heatmap.hpp"

std::vector<Heatmap> FormatReader<Heatmap>::Read(const char *file) {
    FILE *in = fopen(file, "r");
    if (!in) {
        Error("cannot open input file");
    }
    std::vector<Heatmap> ret;
    char buffer[1024];
    char chr[64];
    char name[64];
    long long start, end;
    double value;
    int count;
    while (fgets(buffer, 1024, in) != NULL) {
        if (buffer[0] == '#') continue;
        if ((count = sscanf(buffer, "%s\t%lld\t%lld\t%[^\t]\t%lf\n", chr, &start, &end, name, &value)) == 5) {
            ret.emplace_back(chr, start, end, name, value);
        }
    }
    return ret;
}

void FormatConverter<Heatmap>::Parse(const std::vector<Heatmap>& data) {
    printf("var HEATMAP = [ \"HEATMAP\" , {\n");
    printf("\tinnerRadius: -25, \n");
    printf("\touterRadius: -65, \n");
    printf("\tmaxColor: \"red\", \n");
    printf("\tminColor: \"yellow\", \n");
    printf("}, [\n");
    for (const auto& hist: data) {
        printf("\t{chr: \"%s\", start: \"%lld\", end: \"%lld\", name: \"%s\", value: \"%lf\"},\n"
               , hist.chr_.c_str()
               , hist.start_
               , hist.end_
               , hist.name_.c_str()
               , hist.value_
        );
    }
    printf("]];");
}