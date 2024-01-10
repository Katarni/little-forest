//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#include "App.h"

App::App(int width, int height) {
  crt_tree = Trees::AVL;
  avl_node_ = nullptr;

  window_ = new QMainWindow();
  window_->setFixedSize(width, height);
  window_->setWindowTitle("My Little Forest");
  window_->setStyleSheet("QMainWindow { background: #ebd7f5; }");

  buttons_palette_ = new QWidget(window_);
  buttons_palette_->resize(230, height);
  buttons_palette_->move(width - buttons_palette_->width(), 0);
  buttons_palette_->setStyleSheet("QWidget { background: #fff;"
                                  "border-top-left-radius: 10px;"
                                  "border-bottom-left-radius: 10px; }");

  add_node_edit_ = new QLineEdit(buttons_palette_);
  add_node_edit_->resize(210, 30);
  add_node_edit_->move(10, 35);
  add_node_edit_->setPlaceholderText("New Node");
  add_node_edit_->setStyleSheet("QLineEdit { border: 2px solid #ebd7f5;"
                                "background: #fff;"
                                "color: #000;"
                                "border-radius: 5px; }");

  add_node_btn_ = new QPushButton(buttons_palette_);
  add_node_btn_->resize(70, 30);
  add_node_btn_->move(10, 80);
  add_node_btn_->setText("Add Node");
  add_node_btn_->setStyleSheet("QPushButton { background: #ebd7f5;"
                                "color: #000;"
                                "border-radius: 5px; }");
  connect(add_node_btn_, SIGNAL(released()), this, SLOT(addNode()));

  avl_layout_ = new QGraphicsView(window_);
  avl_layout_->resize(width - 250, height - 50);
  avl_layout_->move(10, 40);

  avl_scene_ = new QGraphicsScene(avl_layout_);
  avl_layout_->move(0, 0);
  avl_scene_->setSceneRect(0, 0, avl_layout_->width(), avl_layout_->height());

  for (auto & node : avl_nodes_list_) {
    delete node;
  }
  drawAVL(avl_node_, 0, 0);

  window_->show();
}

App::~App() {
  delete buttons_palette_;
  delete window_;
}

void App::addNode() {
  int64_t key = add_node_edit_->text().toLongLong();
  add_node_edit_->clear();

  if (crt_tree == Trees::AVL && !AVLNode::existKey(avl_node_, key)) {
    avl_node_ = AVLNode::insertByKey(avl_node_, key);
  }
}

void App::drawAVL(AVLNode* node, int x, int y) {

}
