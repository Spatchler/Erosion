#include "window.hpp"
#include "cube.hpp"

int main() {
  Log::info("game started!");
  static Engine::App& app = Engine::App::get();

  uint window = app.attach(new User::Window("game"));
  uint windowa = app.attach(new User::Window("game1"));

  uint cube = app.getNode(window)->attach(new User::Cube("res/models/cube.obj"));

  Renderer::Shader shaderProgram("res/shaders/default.vs", "res/shaders/default.fs");
  app.defaultShader = &shaderProgram;
  
  while (app.active) {
    app.update();
  }
}
