#pragma once

#include <iostream>

namespace Log {
  inline void print(const char* message) {
    std::cout << message << "\n";
  }
  inline void info(const char* message) {
    std::cout << "[info] " << message << "\n";
  }
  inline void warn(const char* message) {
    std::cout << "\x1b[1;33m[warn] " << message << "\x1b[0m\n";
  }
  inline void critical(const char* message) {
    std::cout << "\x1b[1;31m[critical] " << message << "\x1b[0m\n";
  }
  inline void err(const char* message) {
    std::cerr << "\x1b[1;31m[error] " << message << "\x1b[0m\n";
  }
};
