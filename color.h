#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

void write_color(std::ostream &out, Vec3 pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(pixel_color.x()) << ' '
        << static_cast<int>(pixel_color.y()) << ' '
        << static_cast<int>(pixel_color.z()) << '\n';
}

#endif