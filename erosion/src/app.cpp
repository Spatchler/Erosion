#include "app.hpp"

namespace Engine {
  App App::instance;

  App::App() {
    Log::info("app creation");
    Renderer::init();
  }

  void App::update_callback() {
    active = nodes.size() > 0;
  }

  App::~App() {
    Log::info("app destruction");
    Renderer::destroy();
  }
};
