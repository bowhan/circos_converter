cmake_minimum_required(VERSION 3.2)
project(BiocircosConverter)
include_directories(include)
include_directories($ENV{BOLIB})
add_executable(main
        src/main.cpp

        include/policy.hpp
        include/format/All.hpp
        include/format/Arc.hpp
        include/format/Background.hpp
        include/format/Cnv.hpp
        include/format/Heatmap.hpp
        include/format/Histogram.hpp
        include/format/Line.hpp
        include/format/Link.hpp
        include/format/Scatter.hpp
        include/format/Snp.hpp
        include/format/Text.hpp

        include/parser.hpp
        include/driver.hpp
        include/parser_commands.hpp

        src/driver.cpp
        src/parse_commands.cpp
        )


target_link_libraries(main
        bolib)