#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <cmath>
#include <vector>

namespace math {
  // Vec2
  template <typename T>
  class vec2 {
  public:
    vec2()
    :x(0), y(0), s(x), t(y) {
    }
    vec2(T p_x, T p_y)
    :x(p_x), y(p_y), s(x), t(y) {
    }

    // copy assignment
    vec2& operator=(const vec2& other) {
      x = other.x;
      y = other.y;
      return *this;
    }

    T x;
    T y;
    T& s;
    T& t;

    glm::tvec2<T> getGlmVec() {
      glmVec.x = x;
      glmVec.y = y;
      return glmVec;
    }
  private:
    glm::tvec2<T> glmVec;
  };
  // Vec3
  template <typename T>
  class vec3 {
  public:
    vec3()
    :x(0), y(0), z(0), s(x), t(y), p(z), r(x), g(y), b(z) {
    }
    vec3(T p_x, T p_y, T p_z)
    :x(p_x), y(p_y), z(p_z), s(x), t(y), p(z), r(x), g(y), b(z) {
    }

    // copy assignment
    vec3& operator=(const vec3& other) {
      x = other.x;
      y = other.y;
      z = other.z;
      return *this;
    }

    T x;
    T y;
    T z;
    T& s;
    T& t;
    T& p;
    T& r;
    T& g;
    T& b;

    glm::tvec3<T> getGlmVec() {
      glmVec.x = x;
      glmVec.y = y;
      glmVec.z = z;
      return glmVec;
    }
  private:
    glm::tvec3<T> glmVec;
  };
  // Vec4
  template <typename T>
  class vec4 {
  public:
    vec4()
    :x(0), y(0), z(0), w(0), s(x), t(y), p(z), q(w), r(x), g(y), b(z), a(w) {
    }
    vec4(T p_x, T p_y, T p_z, T p_w)
    :x(p_x), y(p_y), z(p_z), w(p_w), s(x), t(y), p(z), q(w), r(x), g(y), b(z), a(w) {
    }

    // copy assignment
    vec4& operator=(const vec4& other) {
      x = other.x;
      y = other.y;
      z = other.z;
      w = other.w;
      return *this;
    }

    T x;
    T y;
    T z;
    T w;
    T& s;
    T& t;
    T& p;
    T& q;
    T& r;
    T& g;
    T& b;
    T& a;

    glm::tvec4<T> getGlmVec() {
      glmVec.x = x;
      glmVec.y = y;
      glmVec.z = z;
      glmVec.w = w;
      return glmVec;
    }
  private:
    glm::tvec4<T> glmVec;
  };
};
