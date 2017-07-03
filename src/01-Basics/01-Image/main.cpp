#include <iostream>
#include <fstream>
#include "../../utils/math/Vec3.h"

void writeFile();

int main() {
  writeFile();
  return 0;
}

void writeFile() {
  int nx = 1000;
  int ny = 255;

  std::ofstream outfile("hello-world.ppm");

  outfile << "P3\n" << nx << " " << ny << "\n255\n";

  for (auto j = ny - 1; j >= 0; j--) {
    for (auto i = 0; i < nx; i++) {
      Vec3 vec_3(float(i) / float(nx), float(j) / float(ny), .2);

      int ir = int(255.99 * vec_3[0]);
      int ig = int(255.99 * vec_3[1]);
      int ib = int(255.99 * vec_3[2]);
      outfile << ir << " " << ig << " " << ib << "\n";

    }
  }

  outfile << std::endl;
  outfile.close();
}
