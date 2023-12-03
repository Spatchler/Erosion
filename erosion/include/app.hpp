#pragma once

#include "logging.hpp"
#include "node.hpp"
#include "renderer.hpp"

namespace Renderer {
  class Window;
}

namespace Engine {
  class App: public Node {
  public:
    App(const App&) = delete;
    static App& get() { return instance; }

    void update_callback() override;

    Renderer::Window* currentContext;
    
    ~App();
  private:
    App();
    static App instance;
  };
};
