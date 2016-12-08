#include "format/Heatmap.hpp"

std::vector<Heatmap> FormatReader<Heatmap>::Read(const char *file) {
    FILE *in = fopen(file, "r");
    if (!in) {
        Error("cannot open input file");
    }
    std::vector<Heatmap> ret;
    char buffer[1024];
    char chr[64];
    long long start, end;
    int count, num_reads, num_loci;
    char strand;
    char seq[256];
    while (fgets(buffer, 1024, in) != NULL) {
        if (buffer[0] == '#') continue;
        if ((count = sscanf(buffer
                            , "%s\t%lld\t%lld\t%d\t%d\t%c\t%s\n"
                            , chr
                            , &start
                            , &end
                            , &num_reads
                            , &num_loci
                            , &strand
                            , seq)) == 7) {
            ret.emplace_back(chr, start, end, num_reads, num_loci, seq);
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
        printf("\t{chr: \"%s\", start: \"%lld\", end: \"%lld\", value: \"%lf\"},\n"
               , hist.chr_.c_str()
               , hist.start_
               , hist.end_
               , hist.value_
        );
    }
    printf("]];");
}