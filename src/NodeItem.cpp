//
// Created by Тимур Ахметзянов on 10.01.2024.
//

#include "NodeItem.h"

QRectF NodeItem::boundingRect() const {
  return {x_ - radius_ / 2, y_ - radius_ / 2, radius_, radius_};
}

void NodeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
  auto* node = new QGraphicsEllipseItem();
  node->setRect(x_ - radius_ / 2, y_ - radius_ / 2, radius_, radius_);
  node->setBrush(QColor(235, 215, 245));
  node->paint(painter, option, widget);
}
