#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.hpp"
#include "math.hpp"

#include <string>
#include <vector>
#include <array>

namespace Renderer {  
  struct Vertex {
    math::vec3<float> position;
    math::vec3<float> normal;
    math::vec2<float> texCoords;
    math::vec3<float> tangent;
    math::vec3<float> bitangent;
	  //bone indexes which will influence this vertex
    std::array<int, 4> m_BoneIDs;
	  //weights from each bone
    std::array<float, 4> m_Weights;
  };

  struct Texture {
      uint id;
      std::string type;
      std::string path;
  };

  class Mesh {
  public:
    Mesh(std::vector<Vertex> p_vertices, std::vector<uint> p_indices, std::vector<Texture> p_textures);

    void draw(Shader& shader);

    // Mesh data
    std::vector<Vertex>  vertices;
    std::vector<uint>    indices;
    std::vector<Texture> textures;
    uint VAO;
  private:
    uint VBO, EBO;

    void setupMesh();
  };
};
