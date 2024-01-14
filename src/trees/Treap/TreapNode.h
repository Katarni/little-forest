//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "../../includes.h"


class TreapNode {
 public:
  TreapNode(int64_t key, int64_t priority): key_(key), priority_(priority), left_(nullptr), right_(nullptr) {}
  TreapNode(int64_t key, int64_t priority, TreapNode* left, TreapNode* right):
            key_(key),
            priority_(priority),
            left_(left),
            right_(right) {}

  static TreapNode* insert(TreapNode* node, int64_t key, int64_t priority);

  static bool existsKey(TreapNode* node, int64_t key);

 private:
  int64_t key_, priority_;
  TreapNode* left_;
  TreapNode* right_;

  static TreapNode* merge(TreapNode* a, TreapNode* b);

  static std::pair<TreapNode*, TreapNode*> split(TreapNode* node, int64_t k);
};