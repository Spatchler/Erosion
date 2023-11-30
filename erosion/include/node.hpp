#pragma once

#include <vector>
#include <unordered_map>

#include "logging.hpp"

namespace Engine {
  class Node {
  public:
    Node();

    void update();
    uint attach(Node* p_node);
    void detach(Node* p_node);
    uint& get_id();
    Node* getNode(uint p_id) const;
    virtual void update_callback();
    virtual void attach_callback();
    virtual void detach_callback();

    bool active;

    bool isWindow;
    
    virtual ~Node();
  protected:
    uint id;
    uint currentID;
    
    // TODO: Need to change to Node not Node*
    std::unordered_map<uint, Node*> nodes;
  };
}
