//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#include "AVLNode.h"

AVLNode* AVLNode::rightRotation(AVLNode* node_p) {
  AVLNode* node_q = node_p->left_;
  node_p->left_ = node_q->right_;
  node_q->right_ = node_p;
  updateHeight(node_p);
  updateHeight(node_q);
  return node_q;
}

AVLNode* AVLNode::leftRotation(AVLNode* node_p) {
  AVLNode* node_q = node_p->right_;
  node_p->right_ = node_q->left_;
  node_q->left_ = node_p;
  updateHeight(node_p);
  updateHeight(node_q);
  return node_q;
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
