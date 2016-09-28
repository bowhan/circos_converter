#include "format/Link.hpp"

std::vector<Link> FormatReader<Link>::Read(const char *file) {
    FILE *in = fopen(file, "r");
    if (!in) {
        Error("cannot open input file");
    }
    std::vector<Link> ret;
    char buffer[1024];
    char name[64];
    char g1chr[64];
    char g2chr[64];
    char g1name[64];
    char g2name[64];
    long long g1start, g1end, g2start, g2end;
    int count;
    while (fgets(buffer, 1024, in) != NULL) {
        if (buffer[0] == '#') continue;
        if ((count = sscanf(buffer
                            , "%s\t%s\t%lld\t%lld\t%s\t%s\t%lld\t%lld\t%s\n"
                            , name
                            , g1chr, &g1start, &g1end, g1name
                            , g2chr, &g2start, &g2end, g2name)) == 9) {

            ret.emplace_back(name
                             , g1chr, g1start, g1end, g1name
                             , g2chr, g2start, g2end, g2name);
        }
    }
    return ret;
}

void FormatConverter<Link>::Parse(const std::vector<Link>& data) {
    printf("var LINK = [ \"LINK\", {\n");
    printf("\tLinkRadius: 140,\n");
    printf("\tLinkFillColor: \"#F26223\",\n");
    printf("\tLinkWidth: 3,\n");
    printf("\tdisplayLinkAxis: true,\n");
    printf("\tLinkAxisColor: \"#B8B8B8\",\n");
    printf("\tLinkAxisWidth: 0.5,\n");
    printf("\tLinkAxisPad: 3,\n");
    printf("\tdisplayLinkLabel: true,\n");
    printf("\tLinkLabelColor: \"red\",\n");
    printf("\tLinkLabelSize: 13,\n");
    printf("\tLinkLabelPad: 8,\n");
    printf("}, [\n");
    for (const auto& link: data) {
        printf(
            "\t{fusion: \"%s\", "
                "g1chr: \"%s\", g1start: \"%lld\", g1end: \"%lld\", g1name: \"%s\", "
                "g2chr: \"%s\", g2start: \"%lld\", g2end: \"%lld\", g2name: \"%s\"},\n"
            , link.name.c_str()
            , link.g1chr.c_str()
            , link.g1start
            , link.g1end
            , link.g1name.c_str()
            , link.g2chr.c_str()
            , link.g2start
            , link.g2end
            , link.g2name.c_str()
        );
    }
    printf("]];");
}