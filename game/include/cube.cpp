#include "cube.hpp"

namespace User {
  Cube::Cube(const std::string& path)
  :cube(new Renderer::Model(path)) {
    this->attach(cube);
  }

  void Cube::update_callback() {
  }
};
