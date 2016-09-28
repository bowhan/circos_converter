#include <stdlib.h>
#include <iostream>
#include "bolib/program_options/sub.hpp"
#include "parser_commands.hpp"

using namespace std;

inline void ToLower(char *);

int main(int argc, char **argv) {
    if (argc < 3) {
        cerr << "usage: " << argv[0]
             << " ["
             << "snp" << "|"
             << "scatter" << "|"
             << "link" << "|"
             << "cnv" << "|"
             << "arc" << "|"
             << "heatmap" << "|"
             << "histogram" << "|"
             << "line" << "|"
             << "scatter" << "|"
             << "background" << "|"
             << "text"
             << "] "
             << " input_filename" << endl;
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
    string subprogram{argv[1]};
    return subpro.Call(subprogram.c_str(), argc - 1, argv + 1);
}

void ToLower(char *c) {
    while (*c) {
        if (*c >= 65 && *c <= 90) {
            *c += 32;
        }
        ++c;
    }
}