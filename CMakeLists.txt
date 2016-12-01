project(ZamoreCircos CXX C)
cmake_minimum_required(VERSION 2.8)

include(CheckCXXCompilerFlag)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
check_cxx_compiler_flag("-Wno-unused-local-typedefs" HAS_NO_UNUSED_LOCAL_TYPEDEFS)
if (HAS_NO_UNUSED_LOCAL_TYPEDEFS)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-local-typedefs")
endif ()

set(${PROJECT_NAME}_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(${PROJECT_NAME}_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(${PROJECT_NAME}_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)


include_directories(include)
add_executable(circos_converter

        ${${PROJECT_NAME}_INCLUDE_DIR}/policy.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/All.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Arc.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Background.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Cnv.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Heatmap.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Histogram.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Line.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Link.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Scatter.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Snp.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/format/Text.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/parser.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/driver.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/parser_commands.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/utils/kernel_color.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/utils/log.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/utils/sub.hpp
        ${${PROJECT_NAME}_INCLUDE_DIR}/utils/color.hpp

        ${${PROJECT_NAME}_SRC_DIR}/main.cpp
        ${${PROJECT_NAME}_SRC_DIR}/driver.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Arc.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Background.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Cnv.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Heatmap.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Histogram.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Line.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Link.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Scatter.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Snp.cpp
        ${${PROJECT_NAME}_SRC_DIR}/Text.cpp
        ${${PROJECT_NAME}_SRC_DIR}/parse_commands.cpp
        ${${PROJECT_NAME}_SRC_DIR}/log.cpp
        ${${PROJECT_NAME}_SRC_DIR}/color.cpp
        )

INSTALL(TARGETS
        circos_converter
        RUNTIME DESTINATION bin)