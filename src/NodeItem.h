//
// Created by Тимур Ахметзянов on 10.01.2024.
//

#pragma once

#include "includes.h"


class NodeItem: public QGraphicsItem {
 public:
  NodeItem();
  NodeItem(int x, int y, double radius, int64_t key): x_(x), y_(y), radius_(radius), key_(key) {}

 protected:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
  QRectF boundingRect() const override;

 private:
  int x_, y_;
  double radius_;
  int64_t key_;
};

