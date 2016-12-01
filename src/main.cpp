#include <iostream>
#include "utils/sub.hpp"
#include "parser_commands.hpp"

using namespace std;

inline void ToLower(char *c) {
    while (*c) {
        if (*c >= 65 && *c <= 90) {
            *c += 32;
        }
        ++c;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        cerr << R"(
This program generate sample.js for biocircos.
usage:

    program [snp|scatter|link|cnv|arc|heatmap|histogram|line|scatter|background|text] input_file

The format of input files for diff types are as follows:

[ arc ]
chr  start  end  % (i.e, GC content)
> program arc input > arc.js

[ scatter | heatmap | histogram | line | scatter ]
> program [scatter|heatmap|histogram|line|scatter] input.bed2 > output.js


)"
             << endl;
        return 1;
    }

    SubProgram subpro;
    subpro.Register("snp", SnpParser);
    subpro.Register("scatter", ScatterParser);
    subpro.Register("link", LinkParser);
    subpro.Register("cnv", CnvParser);
    subpro.Register("arc", ArcParser);
    subpro.Register("heatmap", HeatmapParser);
    subpro.Register("histogram", HistogramParser);
    subpro.Register("line", LineParser);
    subpro.Register("scatter", ScatterParser);
    subpro.Register("background", BackgroundParser);
    subpro.Register("text", TextParser);

    ToLower(argv[1]);
    return subpro.Call(argv[1], argc - 1, argv + 1);
}

