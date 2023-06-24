#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"

class Sphere {
    protected:
        Vec3 center_;
        double radius_;
        Vec3 color_;
    public:
        Sphere(const Vec3& cen, double r, const Vec3& col)
            : center_(cen), radius_(r), color_(col)
        {}


        Vec3 center() const  { return center_; }
        Vec3 color() const { return color_; }
        double radius() const { return radius_; }

};

#endif