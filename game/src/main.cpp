#include "window.hpp"
#include "cube.hpp"

int main() {
  Log::info("game started!");
  static Engine::App& app = Engine::App::get();

  std::shared_ptr<User::Window> mainWindow(new User::Window("main window"));
  std::shared_ptr<User::Window> secondaryWindow(new User::Window("secondary window"));
  app.attach<User::Window>(mainWindow);
  app.attach<User::Window>(secondaryWindow);
  
  std::shared_ptr<User::Cube> cube(new User::Cube("game/res/models/cube.obj"));
  mainWindow->attach<User::Cube>(cube);

  while (app.active) {
    app.update();
  }
}
