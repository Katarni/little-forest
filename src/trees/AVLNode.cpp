//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#include "AVLNode.h"

AVLNode* AVLNode::rightRotation(AVLNode *p) {
  AVLNode* q = p->left_;
  p->left_ = q->right_;
  q->right_ = p;
  updateHeight(p);
  updateHeight(q);
  return q;
}

AVLNode* AVLNode::leftRotation(AVLNode *p) {
  AVLNode* q = p->right_;
  p->right_ = q->left_;
  q->left_ = p;
  updateHeight(p);
  updateHeight(q);
  return q;
}
