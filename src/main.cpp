#include <stdlib.h>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "bolib/program_options/sub.hpp"
#include "parser_commands.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc < 3) {
        cerr << "usage: " << argv[0] << " subprogram filename" << endl;
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

    string subprogram{argv[1]};
    boost::to_lower(subprogram);
    return subpro.Call(subprogram.c_str(), argc - 1, argv + 1);
}