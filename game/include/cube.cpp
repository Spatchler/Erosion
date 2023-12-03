#include "cube.hpp"

namespace User {
  Cube::Cube(const std::string& path)
  :model(new Renderer::Model(path)), modelID(this->attach<Renderer::Model>(model)){
  }

  void Cube::update_callback() {
  }
};
