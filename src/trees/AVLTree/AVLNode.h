//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "../../includes.h"


class AVLNode {
 public:
  explicit AVLNode(int64_t key): key_(key), left_(nullptr), right_(nullptr), height_(1) {}

  static int getHeight(AVLNode* node) {
    return node != nullptr ? node->height_ : 0;
  }

  static int getBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return getHeight(node->right_) - getHeight(node->left_);
  }

  static AVLNode* restoreBalance(AVLNode* node);

  static AVLNode* insertByKey(AVLNode* node, int64_t key);

  static AVLNode* eraseByKey(AVLNode* node, int64_t key);

  static bool existKey(AVLNode* node, int64_t key);

  static AVLNode* addNRandomNodes(AVLNode* node, int n);

  int64_t getKey() const {
    return key_;
  }

 private:
  int64_t key_;
  int height_;

  AVLNode* left_;
  AVLNode* right_;

  static void updateHeight(AVLNode* node) {
    node->height_ = getHeight(node->left_) > getHeight(node->right_) ? getHeight(node->left_) : getHeight(node->right_);
  }

  static AVLNode* rightRotation(AVLNode* node);
  static AVLNode* leftRotation(AVLNode* node);

  static AVLNode* findMinNode(AVLNode* node) {
    return node->left_ != nullptr ? findMinNode(node->left_) : node;
  }

  static AVLNode* eraseMinNode(AVLNode* node);
};
