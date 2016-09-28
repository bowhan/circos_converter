#include "parser_commands.hpp"

#define PARSEMAIN(FORMAT) \
        using ParserType = Parser<FORMAT>; \
        ParserType parser; \
        Driver d{argv[1], &parser}; \
        d.Read().Parse(); \
        return 0;

int SnpParser(int argc, char **argv) {
    PARSEMAIN(Snp)
}

int ScatterParser(int argc, char **argv) {
    PARSEMAIN(Scatter)
}

int LinkParser(int argc, char **argv) {
    PARSEMAIN(Link)
}

int CnvParser(int argc, char **argv) {
    PARSEMAIN(Cnv)
}

int ArcParser(int argc, char **argv) {
    PARSEMAIN(Arc)
}

int HeatmapParser(int argc, char **argv) {
    PARSEMAIN(Heatmap)
}

int HistogramParser(int argc, char **argv) {
    PARSEMAIN(Histogram)
}

int LineParser(int argc, char **argv) {
    PARSEMAIN(Line)
}

int BackgroundParser(int argc, char **argv) {
    PARSEMAIN(Background)
}

int TextParser(int argc, char **argv) {
    PARSEMAIN(Text)
}
