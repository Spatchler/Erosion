#pragma once

#include <vector>
#include <unordered_map>
#include <memory>

#include "logging.hpp"

namespace Engine {
  class Node {
  public:
    Node();

    void update();

    template <class T>
    uint attach(std::shared_ptr<T> p_node) {
      activeNodes.insert(std::pair<uint, std::shared_ptr<T>>(currentID, p_node));
      activeNodes.at(currentID)->id = currentID;
      ++currentID;
      return currentID - 1;
    }
    void detach(uint p_id);
    
    uint& get_id();
    std::shared_ptr<Node> getNode(uint p_id) const;
    virtual void update_callback();
    virtual void attach_callback();
    virtual void detach_callback();

    bool active;

    bool isWindow;
    
    virtual ~Node();
  protected:
    uint id;
    uint currentID;
    
    std::unordered_map<uint, std::shared_ptr<Node>> activeNodes;
    std::unordered_map<uint, std::shared_ptr<Node>> inactiveNodes;
  };
}
