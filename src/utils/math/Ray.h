#ifndef PLAYRTX_SRC_UTILS_MATH_RAY_H_
#define PLAYRTX_SRC_UTILS_MATH_RAY_H_

#include "Vec3.h"

class Ray {
public:
  Vec3 A;
  Vec3 B;

  Ray() = default;
  Ray(const Vec3 &a, const Vec3 &b) {
    A = a;
    B = b;
  }

  const Vec3 origin() { return A; }
  const Vec3 direction() { return B; }
  const Vec3 pointAtParameter(float t) { return A + t * B; }
};

#endif //PLAYRTX_SRC_UTILS_MATH_RAY_H_
