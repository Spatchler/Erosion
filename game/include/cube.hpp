#pragma once

#include "app.hpp"

namespace User {
  class Cube: public Engine::Node {
  public:
    Cube(const std::string& path);

    void update_callback() override;
    
    Renderer::Model* cube;
  };
};
