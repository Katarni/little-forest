//
// Created by Тимур Ахметзянов on 09.01.2024.
//

#pragma once
#include "includes.h"

class App: QMainWindow {
  Q_OBJECT

 public:
  App(int width, int height);

 private:
  QMainWindow* window_;
};
