#include "window.hpp"

namespace User {
  Window::Window(const char* p_title)
  :window(new Renderer::Window(p_title)), windowID(this->attach<Renderer::Window>(window)) {
  }

  void Window::update_callback() {
    window->clear(math::vec4<float>(1.0f, 1.0f, 1.0f, 1.0f));
    if (window->shouldClose) {
      active = false;
    }
  }
};
