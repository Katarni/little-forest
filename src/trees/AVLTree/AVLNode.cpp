//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#include "AVLNode.h"

AVLNode* AVLNode::rightRotation(AVLNode* node) {
  AVLNode* left_node = node->left_;
  node->left_ = left_node->right_;
  left_node->right_ = node;
  updateHeight(node);
  updateHeight(left_node);
  return left_node;
}

AVLNode* AVLNode::leftRotation(AVLNode* node) {
  AVLNode* right_node = node->right_;
  node->right_ = right_node->left_;
  right_node->left_ = node;
  updateHeight(node);
  updateHeight(right_node);
  return right_node;
}

AVLNode* AVLNode::restoreBalance(AVLNode* node) {
  updateHeight(node);
  if (getBalanceFactor(node) == 2) {
    if (getBalanceFactor(node->right_) < 0) {
      node->right_ = rightRotation(node->right_);
    }
    return leftRotation(node);
  }

  if (getBalanceFactor(node) == -2) {
    if (getBalanceFactor(node->left_) < 0) {
      node->left_ = leftRotation(node->left_);
    }
    return rightRotation(node);
  }
  return node;
}

AVLNode* AVLNode::eraseMinNode(AVLNode* node) {
  if (node->left_ == nullptr) {
    return node->right_;
  }
  node->left_ = eraseMinNode(node->left_);
  return restoreBalance(node);
}

AVLNode* AVLNode::insertByKey(AVLNode* node, int64_t key)  {
  if (node == nullptr) {
    return new AVLNode(key);
  }
  if (key < node->key_) {
    node->left_ = insertByKey(node->left_, key);
  } else {
    node->right_ = insertByKey(node->right_, key);
  }

  return restoreBalance(node);
}

AVLNode* AVLNode::eraseByKey(AVLNode* node, int64_t key) {
  if (node == nullptr) {
    return nullptr;
  }

  if (key < node->key_) {
    node->left_ = eraseByKey(node->left_, key);
  } else if (key > node->key_) {
    node->right_ = eraseByKey(node->right_, key);
  } else {
    AVLNode* left_node = node->left_;
    AVLNode* right_node = node->right_;
    delete node;

    if (right_node == nullptr) {
      return left_node;
    }

    AVLNode* min_node = findMinNode(right_node);
    min_node->right_ = eraseMinNode(right_node);
    min_node->left_ = left_node;
    return restoreBalance(min_node);
  }

  return restoreBalance(node);
}

bool AVLNode::existKey(AVLNode* node, int64_t key) {
  if (node == nullptr) {
    return false;
  }

  if (key < node->key_) {
    return existKey(node->left_, key);
  } else if (key > node->key_) {
    return existKey(node->right_, key);
  }

  return true;
}

AVLNode* AVLNode::addNRandomNodes(AVLNode* node, int n) {
  std::random_device random;
  std::mt19937 get(random());
  for (int i = 0; i < n; ++i) {
    int64_t key = get() % kMod;
    while (!existKey(node, key)) {
      ++key;
    }
    node = insertByKey(node, key);
  }
  return node;
}
