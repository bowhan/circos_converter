#include "utils/color.hpp"
#include <algorithm>

std::string to_rgb(double value, double minimun, double maximum) {
    double ratio = 2 * (value - minimun) / (maximum - minimun);
    int b = std::max(0, int(255 * (1 - ratio)));
    int r = std::max(0, int(255 * (ratio - 1)));
    int g = 255 - b - r;
    return std::string{"rgb"} + '('
        + std::to_string(r) + ','
        + std::to_string(g) + ','
        + std::to_string(b) + ')';
}

std::string to_grey(double value, double minimum, double maximum) {
    double ratio = (value - minimum) / (maximum - minimum);
    int g = int(255 * (1 - ratio));
    return std::string{"rgb"} + '('
        + std::to_string(g) + ','
        + std::to_string(g) + ','
        + std::to_string(g) + ')';
}
