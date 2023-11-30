#include "node.hpp"

namespace Engine {
  Node::Node()
  :active(true), id(0), currentID(0) {
  }

  void Node::update() {
    this->update_callback();
    for (auto i = nodes.begin(); i != nodes.end();) {
      if (i->second->active) {
        i->second->update();
        ++i;
      }
      else {
        delete i->second;
        i->second = nullptr;
        i = nodes.erase(i);
      }
    }
  }

  uint Node::attach(Node* p_node) {
    this->attach_callback();
    p_node->get_id() = currentID;
    nodes.insert(std::pair<uint, Node*>(p_node->get_id(), p_node));
    ++currentID;
    return p_node->get_id();
  }

  void Node::detach(Node* p_node) {
    this->detach_callback();
    nodes.erase(p_node->get_id());
  }

  uint& Node::get_id() {
    return id;
  }

  Node* Node::getNode(uint p_id) const {
    auto node = nodes.find(p_id);
    if (node == nodes.end())
      return nullptr;
    else
      return node->second;
  }

  void Node::update_callback() {}
  void Node::attach_callback() {}
  void Node::detach_callback() {}

  Node::~Node() {
    for (auto i = nodes.begin(); i != nodes.end();) {
      delete i->second;
      i->second = nullptr;
      i = nodes.erase(i);
    }
  }
};
