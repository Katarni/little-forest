//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#include "App.h"

App::App(int width, int height) {
  window_ = new QMainWindow();
  window_->setFixedSize(width, height);
  window_->setWindowTitle("My Little Forest");
  window_->setStyleSheet("QMainWindow { background: #fff; }");

  window_->show();
}
