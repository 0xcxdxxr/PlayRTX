#include <iostream>
#include <fstream>

#include "../../utils/math/Vec3.h"
#include "../../utils/math/Ray.h"

void writeFile();

Vec3 color(Ray ray) {
  Vec3 unitDirection = unitVector(ray.direction());
  auto t = 0.5f * (unitDirection.y() + 1.f);
  return (1.f - t) * Vec3(1.f, 1.f, 1.f) + t * Vec3(.5f, .7f, 1.f);
}

int main() {
  writeFile();
  return 0;
}

void writeFile() {
  int nx = 1000;
  int ny = 255;

  std::ofstream outfile("ray.ppm");

  Vec3 lowerLeftCorner(-2.f, -1.f, -1.f);
  Vec3 horizontal(4.f, 0.f, 0.f);
  Vec3 vertical(0.f, 2.f, 0.f);
  Vec3 origin(0.f, 0.f, 0.f);

  outfile << "P3\n" << nx << " " << ny << "\n255\n";

  for (auto j = ny - 1; j >= 0; j--) {
    for (auto i = 0; i < nx; i++) {
      Vec3 vec3(float(i) / float(nx), float(j) / float(ny), .2);
      Ray ray(origin, lowerLeftCorner + vec3.x() * horizontal + vec3.y() * vertical);
      Vec3 col = color(ray);
      int ir = int(255.99 * col[0]);
      int ig = int(255.99 * col[1]);
      int ib = int(255.99 * col[2]);
      outfile << ir << " " << ig << " " << ib << "\n";

    }
  }

  outfile << std::endl;
  outfile.close();
}
