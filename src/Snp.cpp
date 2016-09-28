#include "format/Snp.hpp"

const char *const Snp::default_color = "rgb(0,0,0)";

std::vector<Snp> FormatReader<Snp>::Read(const char *file) {
    FILE *in = fopen(file, "r");
    if (!in) {
        Error("cannot open input file");
    }
    std::vector<Snp> ret;
    char buffer[1024];
    char chr[64];
    char name[64];
    long long pos;
    double value;
    int count;
    while (fgets(buffer, 1024, in) != NULL) {
        if (buffer[0] == '#') continue;
        if ((count = sscanf(buffer, "%s\t%lld\t%lf\t%s\n", chr, &pos, &value, name)) == 4) {
            ret.emplace_back(chr, pos, value, name);
        }
    }
    return ret;
}

void FormatConverter<Snp>::Parse(const std::vector<Snp>& data) {
    printf("var SNP = [ \"SNP\", {\n");
    printf("\tmaxRadius: 205,\n");
    printf("\tminRadius: 153,\n");
    printf("\tSNPFillColor: \"#9400D3\",\n");
    printf("\tPointType: \"circle\",\n");
    printf("\tcircleSize: 2,\n");
    printf("\trectWidth: 2,\n");
    printf("\trectHeight: 2,\n");
    printf("}, [\n");
    for (const auto& snp: data) {
        printf("\t{chr: \"%s\", pos: \"%lld\", value: \"%lf\", des: \"%s\", color: \"%s\"},\n"
               , snp.chr_.c_str()
               , snp.pos_
               , snp.value_
               , snp.name_.c_str()
               , Snp::default_color
        );
    }
    printf("]];");
}
