#include "utils/color.hpp"
#include "format/Arc.hpp"
#include <algorithm>

std::vector<Arc> FormatReader<Arc>::Read(const char *filename) {
    FILE *in = fopen(filename, "r");
    if (!in) {
        Error("cannot open input file");
    }
    std::vector<Arc> ret;
    char buffer[1024];
    char chr[64];
    double percent;
    long long start, end;
    int count;
    while (fgets(buffer, 1024, in) != NULL) {
        if (buffer[0] == '#') continue;
        if ((count = sscanf(buffer, "%s\t%lld\t%lld\t%lf\n", chr, &start, &end, &percent)) == 4) {
            ret.emplace_back(chr, start, end, to_grey(percent));
        }
    }
    return ret;
}

void FormatConverter<Arc>::Parse(const std::vector<Arc>& data) {
    printf("var ARC = [ \"ARC\", {\n");
    printf("\tinnerRadius: -0,\n");
    printf("\touterRadius: -0,\n");
    printf("}, [\n");
    for (const auto& arc: data) {
        printf("\t{chr: \"%s\", start: \"%lld\", end: \"%lld\", color: \"%s\"},\n"
               , arc.chr_.c_str()
               , arc.start_
               , arc.end_
               , arc.color_.c_str()
        );
    }
    printf("]];");
}