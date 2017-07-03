#ifndef PLAYRTX_SRC_UTILS_MATH_VEC3_H_
#define PLAYRTX_SRC_UTILS_MATH_VEC3_H_

#include <cmath>
#include <cstdlib>
#include <iostream>

class Vec3 {
public:
  float vec[3]{};

  Vec3() = default;

  Vec3(float x, float y, float z = 0) {
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
  }

  inline float x() { return vec[0]; }
  inline float y() { return vec[1]; }
  inline float z() { return vec[2]; }
  inline float r() { return vec[0]; }
  inline float g() { return vec[1]; }
  inline float b() { return vec[2]; }

  inline const Vec3 &operator+() const { return *this; }
  inline Vec3 operator-() const { return Vec3(-vec[0], -vec[1], -vec[2]); }
  inline float operator[](int i) const { return vec[i]; }
  inline float &operator[](int i) { return vec[i]; }

  inline Vec3 &operator+=(const Vec3 &v2);
  inline Vec3 &operator-=(const Vec3 &v2);
  inline Vec3 &operator*=(const Vec3 &v2);
  inline Vec3 &operator/=(const Vec3 &v2);
  inline Vec3 &operator*=(float t);
  inline Vec3 &operator/=(float t);

  [[nodiscard]] inline float length() const { return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]); }
  [[nodiscard]] inline float squaredLength() const { return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]; }
  inline void makeUnitVector();
};

inline std::istream &operator>>(std::istream &is, Vec3 &t) {
  is >> t.vec[0] >> t.vec[1] >> t.vec[2];
  return is;
}

inline std::ostream &operator<<(std::ostream &os, const Vec3 &t) {
  os << t.vec[0] << " " << t.vec[1] << " " << t.vec[2];
  return os;
}

inline void Vec3::makeUnitVector() {
  float k = 1.0 / sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
  vec[0] *= k;
  vec[1] *= k;
  vec[2] *= k;
}

inline Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
  return Vec3(v1.vec[0] + v2.vec[0], v1.vec[1] + v2.vec[1], v1.vec[2] + v2.vec[2]);
}

inline Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
  return Vec3(v1.vec[0] - v2.vec[0], v1.vec[1] - v2.vec[1], v1.vec[2] - v2.vec[2]);
}

inline Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
  return Vec3(v1.vec[0] * v2.vec[0], v1.vec[1] * v2.vec[1], v1.vec[2] * v2.vec[2]);
}

inline Vec3 operator/(const Vec3 &v1, const Vec3 &v2) {
  return Vec3(v1.vec[0] / v2.vec[0], v1.vec[1] / v2.vec[1], v1.vec[2] / v2.vec[2]);
}

inline Vec3 operator*(float t, const Vec3 &v) {
  return Vec3(t * v.vec[0], t * v.vec[1], t * v.vec[2]);
}

inline Vec3 operator/(Vec3 v, float t) {
  return Vec3(v.vec[0] / t, v.vec[1] / t, v.vec[2] / t);
}

inline Vec3 operator*(const Vec3 &v, float t) {
  return Vec3(t * v.vec[0], t * v.vec[1], t * v.vec[2]);
}

inline float dot(const Vec3 &v1, const Vec3 &v2) {
  return v1.vec[0] * v2.vec[0] + v1.vec[1] * v2.vec[1] + v1.vec[2] * v2.vec[2];
}

inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
  return Vec3((v1.vec[1] * v2.vec[2] - v1.vec[2] * v2.vec[1]),
              (-(v1.vec[0] * v2.vec[2] - v1.vec[2] * v2.vec[0])),
              (v1.vec[0] * v2.vec[1] - v1.vec[1] * v2.vec[0]));
}

inline Vec3 &Vec3::operator+=(const Vec3 &v) {
  vec[0] += v.vec[0];
  vec[1] += v.vec[1];
  vec[2] += v.vec[2];
  return *this;
}

inline Vec3 &Vec3::operator*=(const Vec3 &v) {
  vec[0] *= v.vec[0];
  vec[1] *= v.vec[1];
  vec[2] *= v.vec[2];
  return *this;
}

inline Vec3 &Vec3::operator/=(const Vec3 &v) {
  vec[0] /= v.vec[0];
  vec[1] /= v.vec[1];
  vec[2] /= v.vec[2];
  return *this;
}

inline Vec3 &Vec3::operator-=(const Vec3 &v) {
  vec[0] -= v.vec[0];
  vec[1] -= v.vec[1];
  vec[2] -= v.vec[2];
  return *this;
}

inline Vec3 &Vec3::operator*=(const float t) {
  vec[0] *= t;
  vec[1] *= t;
  vec[2] *= t;
  return *this;
}

inline Vec3 &Vec3::operator/=(const float t) {
  auto k = float(1.0 / t);

  vec[0] *= k;
  vec[1] *= k;
  vec[2] *= k;
  return *this;
}

inline Vec3 unitVector(Vec3 v) {
  return v / v.length();
}

#endif // PLAYRTX_SRC_UTILS_MATH_VEC3_H_
