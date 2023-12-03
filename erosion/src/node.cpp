#include "node.hpp"

namespace Engine {
  Node::Node()
  :active(true), id(0), currentID(0) {
  }

  void Node::update() {
    this->update_callback();
    for (auto i = activeNodes.begin(); i != activeNodes.end();) {
      if (i->second->active) {
        i->second->update();
        ++i;
      }
      else {
        inactiveNodes.insert(*i);
        i = activeNodes.erase(i);
      }
    }
  }

  void Node::detach(uint p_id) {
    auto a = activeNodes.find(p_id);
    if (a == activeNodes.end())
      inactiveNodes.erase(p_id);
    else
      activeNodes.erase(p_id);
  }

  uint& Node::get_id() {
    return id;
  }

  std::shared_ptr<Node> Node::getNode(uint p_id) const {
    auto node = activeNodes.find(p_id);
    if (node == activeNodes.end())
      return nullptr;
    else
      return node->second;
  }

  void Node::update_callback() {}
  void Node::attach_callback() {}
  void Node::detach_callback() {}

  Node::~Node() {
    for (auto i = activeNodes.begin(); i != activeNodes.end();) {
      i = activeNodes.erase(i);
    }
    for (auto i = inactiveNodes.begin(); i != inactiveNodes.end();) {
      i = inactiveNodes.erase(i);
    }
  }
};
