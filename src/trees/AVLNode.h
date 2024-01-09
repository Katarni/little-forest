//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "../includes.h"


class AVLNode {
 public:
  explicit AVLNode(int64_t key): key_(key), left_(nullptr), right_(nullptr), height_(1) {}

  static uint8_t getHeight(AVLNode* node) {
    return node != nullptr ? node->height_ : 0;
  }

  static uint8_t getBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return getHeight(node->right_) - getHeight(node->left_);
  }

 private:
  int64_t key_;
  uint8_t height_;

  AVLNode* left_;
  AVLNode* right_;

  static void updateHeight(AVLNode* node) {
    node->height_ = getHeight(node->left_) > getHeight(node->right_) ? getHeight(node->left_) : getHeight(node->right_);
  }

  static AVLNode* rightRotation(AVLNode* p);
  static AVLNode* leftRotation(AVLNode* p);
};
