#pragma once

#include "app.hpp"

namespace User {
  class Window: public Engine::Node {
  public:
    Window(const char* p_title);

    void update_callback() override;
    
    std::shared_ptr<Renderer::Window> window;
    uint windowID;
  };
};
