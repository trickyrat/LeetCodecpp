#pragma once
#include <vector>

class Node {
public:
  int val;
  std::vector<Node*> children;
  Node() {}
  Node(int _val, std::vector<Node*> _children)
    : val(_val), children(_children) {}
};


