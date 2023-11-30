#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h>

#include <map>
#include <vector>
#include <array>

#include "logging.hpp"
#include "math.hpp"
#include "node.hpp"

#include "mesh.hpp"
#include "shader.hpp"
#include "model.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

namespace Renderer {
  void init();
  void destroy();

  class Window: public Engine::Node {
  public:
    Window(const char* p_title);

    GLFWwindow* getGLFWwindow() { return glfwWindow; }

    void update_callback() override;

    void clear(math::vec4<float> p_color);
    void captureCursor();

    bool vsync;
    bool wireframe;

    bool shouldClose;

    math::vec2<int> size;
    
    ~Window();
  private:
    GLFWwindow* glfwWindow;

    const char* title;
  };
};
