#ifndef COMBOBOXITEMDELEGATE_HPP_
#define COMBOBOXITEMDELEGATE_HPP_

#include <QStyledItemDelegate>


class ComboBoxItemDelegate : public QStyledItemDelegate {
Q_OBJECT

public:

    explicit ComboBoxItemDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const;

    void setModelData(QWidget *, QAbstractItemModel *, const QModelIndex &) const;

    void updateEditorGeometry(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const;

    void setEditorData(QWidget *, const QModelIndex &) const;

    void paint(QPainter *, const QStyleOptionViewItem &, const QModelIndex &) const;


};


#endif // COMBOBOXITEMDELEGATE_HPP_
