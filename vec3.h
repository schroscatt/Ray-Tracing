#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class Vec3
{
 protected:
    float x_, y_, z_;

 public:
    Vec3(float _x, float _y, float _z)
     : x_(_x), y_(_y), z_(_z) 
    {
    
    }     

    float x() const  { return x_; }
    float y() const { return y_; }
    float z() const { return z_; }
    
    Vec3 sub(const Vec3 &v) 
    {
        return Vec3(x_-v.x(), y_-v.y(), z_-v.z());
    }

    Vec3 add(const Vec3 &v) {
        return Vec3(x_+v.x(), y_+v.y(), z_+v.z());
    }

    Vec3 scale(double t) {
        return Vec3(x_*t, y_*t, z_*t);
    }

    Vec3 unit_vector() {
        double len = length();
        return Vec3(x_/len, y_/len, z_/len);

    }

    Vec3 operator-() const { return Vec3(-x_, -y_, -z_); }

    Vec3& operator+=(const Vec3 &v) {
        x_ += v.x();
        y_ += v.y();
        z_ += v.z();
        return *this;
     }

    Vec3& operator*=(const double t) {
        x_ *= t;
        y_ *= t;
        z_ *= t;
        return *this;
    }

    Vec3& operator/=(const double t) {
        return *this *= 1/t;
    }

    double length(){
        return sqrt(x_*x_ + y_*y_ + z_*z_);
    }
    
};


inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline Vec3 operator*(double t, const Vec3 &v) {
    return Vec3(t*v.x(), t*v.y(), t*v.z());
}

inline Vec3 operator*(const Vec3 &v, double t) {
    return t * v;
}

inline Vec3 operator/(Vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const Vec3 &u, const Vec3 &v) {
    return u.x() * v.x()
         + u.y() * v.y()
         + u.z() * v.z();
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.z());
}

inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}

#endif
