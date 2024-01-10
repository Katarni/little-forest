//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once

#include "trees/AVLTree/AVLNode.h"
#include "NodeItem.h"
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
  ~App() override;

 private slots:
  void addNode();

 private:
  Trees crt_tree;

  AVLNode* avl_node_;
  std::vector<NodeItem*> avl_nodes_list_;

  QMainWindow* window_;
  QWidget* buttons_palette_;
  QLineEdit* add_node_edit_;
  QPushButton* add_node_btn_;

  QGraphicsView* avl_layout_;
  QGraphicsScene* avl_scene_;

  void drawAVL(AVLNode* node, int x, int y);
};
