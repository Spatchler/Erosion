#pragma once

#include "logging.hpp"
#include "node.hpp"
#include "renderer.hpp"

namespace Engine {
  class App: public Node {
  public:
    App(const App&) = delete;
    static App& get() { return instance; }

    void update_callback() override;
    
    Renderer::Shader* defaultShader;
    
    ~App();
  private:
    App();
    static App instance;
  };
};
