//
// Created by Тимур Ахметзянов on 10.01.2024.
//

#include "NodeItem.h"

QRectF NodeItem::boundingRect() const {
  return {x_ - radius_ / 2, y_ - radius_ / 2, radius_, radius_};
}

void NodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  painter->setPen(Qt::NoPen);
  painter->setBrush(QColor(235, 215, 245));
  painter->drawEllipse(int(x_ - radius_ / 2), int(y_ - radius_ / 2), (int)radius_, (int)radius_);
}

NodeItem::NodeItem() : QGraphicsItem() {
  x_ = 0;
  y_ = 0;
  radius_ = 0;
  key_ = 0;
}
