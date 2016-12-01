#include "format/Line.hpp"

std::vector<Line> FormatReader<Line>::Read(const char *file) {
    FILE *in = fopen(file, "r");
    if (!in) {
        Error("cannot open input file");
    }
    std::vector<Line> ret;
    char buffer[1024];
    char chr[64];
    long long pos;
    long long end;
    double value;
    int count;
    while (fgets(buffer, 1024, in) != NULL) {
        if (buffer[0] == '#') continue;
        if ((count = sscanf(buffer, "%s\t%lld\t%lld\t%lf\n", chr, &pos, &end, &value)) == 4) {
            ret.emplace_back(chr, pos, value);
        }
    }
    return ret;
}

void FormatConverter<Line>::Parse(const std::vector<Line>& data) {
    printf("var LINE = [ \"LINE\" , {\n");
    printf("\tmaxRadius: 220, \n");
    printf("\tminRadius: 170, \n");
    printf("\tLineColor: \"#EEAD0E\", \n");
    printf("\tLineWidth: 2, \n");
    printf("}, [\n");
    for (const auto& arc: data) {
        printf("\t{chr: \"%s\", pos: \"%lld\", value: \"%lf\"},\n"
               , arc.chr_.c_str()
               , arc.pos_
               , arc.value_
        );
    }
    printf("]];");
}