//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "trees/AVLTree/AVLNode.h"
#include "includes.h"


enum class Trees {
  AVL,
  RB,
  Splay,
  Treap
};


class App: QMainWindow {
  Q_OBJECT

 public:
  App(int width, int height);
  ~App();

 private:
  Trees crt_tree;

  AVLNode* avl_node_;

  QMainWindow* window_;
  QWidget* buttons_palette_;
  QWidget* add_node_button_;
};
