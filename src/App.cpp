//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#include "App.h"

App::App(int width, int height) {
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

  window_->show();
}
