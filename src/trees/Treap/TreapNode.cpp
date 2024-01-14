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

  if (a->priority_ > b->priority_) {
    a->right_ = merge(a->right_, b);
    return b;
  }

  b->left_ = merge(a, b->left_);
  return b;
}

std::pair<TreapNode*, TreapNode*> TreapNode::split(TreapNode* node, int64_t k) {
  if (node == nullptr) {
    return {nullptr, nullptr};
  }

  if (node->key_ < k) {
    auto divided = split(node->right_, k);
    node->right_ = divided.first;
    return {node, divided.second};
  }

  auto divided = split(node->left_, k);
  node->left_ = divided.second;
  return {divided.first, node};
}

TreapNode *TreapNode::insert(TreapNode *node, int64_t key, int64_t priority) {
  if (node == nullptr) {
    return new TreapNode(key, priority);
  }

  if (priority > node->priority_) {
    auto divided = split(node, key);
    return new TreapNode(key, priority, divided.first, divided.second);
  }

  if (key > node->key_) {
    node->right_ = insert(node->right_, key, priority);
  } else {
    node->left_ = insert(node->left_, key, priority);
  }
  return node;
}

bool TreapNode::existsKey(TreapNode *node, int64_t key) {
  if (node == nullptr) {
    return false;
  }

  if (node->key_ == key) {
    return true;
  } else if (node->key_ < key) {
    return existsKey(node->left_, key);
  }
  return existsKey(node->right_, key);
}

TreapNode *TreapNode::removeKey(TreapNode *node, int64_t key) {
  if (node == nullptr) return nullptr;
  if (node->key_ == key) {
    node = merge(node->left_, node->right_);
  } else if (key < node->key_) {
    node->left_ = removeKey(node->left_, key);
  } else {
    node->right_ = removeKey(node->right_, key);
  }
  return node;
}
