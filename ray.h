#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
    protected:
        Vec3 orig, dir;
    public:
        Ray(const Vec3& _origin, const Vec3& direction)
            : orig(_origin), dir(direction)
        {}

        Vec3 origin() const  { return orig; }
        Vec3 direction() const { return dir; }

        Vec3 at(double t) const {
            return orig + t*dir;
        }

};

#endif