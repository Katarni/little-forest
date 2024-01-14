//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "../../includes.h"


class TreapNode {
 public:


 private:
  int64_t x_, y_;
  TreapNode* left;
  TreapNode* right;

  TreapNode* merge(TreapNode* a, TreapNode* b);

  std::pair<TreapNode*, TreapNode*> split(TreapNode* node, int64_t k);
};