#ifndef DATAEDITDELEGATE_HPP_
#define DATAEDITDELEGATE_HPP_

#include <QItemDelegate>
#include <QObject>

class DataEditDelegate : public QItemDelegate {
Q_OBJECT
public:
    DataEditDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const;

    void setModelData(QWidget *, QAbstractItemModel *, const QModelIndex &) const;

    void updateEditorGeometry(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const;

    void setEditorData(QWidget *, const QModelIndex &) const;

    void paint(QPainter *, const QStyleOptionViewItem &, const QModelIndex &) const;

};


#endif // DATAEDITDELEGATE_HPP_
