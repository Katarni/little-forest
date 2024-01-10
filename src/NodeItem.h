//
// Created by Тимур Ахметзянов on 10.01.2024.
//

#pragma once

#include "includes.h"


class NodeItem: QGraphicsItem {
 public:
  NodeItem(int x, int y, double radius, QString key): x_(x), y_(y), radius_(radius), key_(std::move(key)) {}

 protected:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
  QRectF boundingRect() const override;

 private:
  int x_, y_;
  double radius_;
  QString key_;
};

