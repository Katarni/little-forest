//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#include "TreapNode.h"

TreapNode *TreapNode::merge(TreapNode *a, TreapNode *b) {
  if (a == nullptr) {
    return b;
  }
  if (b == nullptr) {
    return a;
  }

  if (a->y_ > b->y_) {
    a->right = merge(a->right, b);
    return b;
  }

  b->left = merge(a, b->left);
  return b;
}

std::pair<TreapNode*, TreapNode*> TreapNode::split(TreapNode* node, int64_t k) {
  if (node == nullptr) {
    return {nullptr, nullptr};
  }

  if (node->x_ < k) {
    auto divided = split(node->right, k);
    node->right = divided.first;
    return {node, divided.second};
  }

  auto divided = split(node->left, k);
  node->left = divided.second;
  return {divided.first, node};
}

