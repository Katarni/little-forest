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

  int64_t getMaxVal(TreapNode* node);
  int64_t getMinVal(TreapNode* node);

  TreapNode* merge(TreapNode* a, TreapNode* b);
};