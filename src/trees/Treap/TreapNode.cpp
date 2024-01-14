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

  if (getMaxVal(a) > getMinVal(b)) {
    return nullptr;
  }

  if (a->y_ > b->y_) {
    a->right = merge(a->right, b);
    return b;
  }

  b->left = merge(a, b->left);
  return b;
}

int64_t TreapNode::getMaxVal(TreapNode *node) {
  int64_t max_val = node->x_;
  if (node->left != nullptr) {
    max_val = std::max(max_val, getMaxVal(node->left));
  }
  if (node->right != nullptr) {
    max_val = std::max(max_val, getMaxVal(node->right));
  }
  return max_val;
}

int64_t TreapNode::getMinVal(TreapNode *node) {
  int64_t min_val = node->x_;
  if (node->left != nullptr) {
    min_val = std::min(min_val, getMinVal(node->left));
  }
  if (node->right != nullptr) {
    min_val = std::min(min_val, getMinVal(node->right));
  }
  return min_val;
}

