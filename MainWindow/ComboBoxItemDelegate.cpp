#include "ComboBoxItemDelegate.hpp"

#include <QComboBox>
#include <QApplication>

ComboBoxItemDelegate::ComboBoxItemDelegate(QObject *parent) : QStyledItemDelegate(parent) {

}

QWidget *ComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const {
    auto *comboBox = new QComboBox(parent);
    comboBox->addItems(QStringList() << "booked" << "not booked");
    comboBox->setCurrentIndex(0);
    return comboBox;
}

void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (index.column() == 4) {
        QString value = index.model()->data(index, Qt::EditRole).toString();
        QComboBox *comboBox = static_cast<QComboBox *>(editor);
        if (value == "booked")
            comboBox->setCurrentIndex(0);
        else if (value == "not booked")
            comboBox->setCurrentIndex(1);
    }
}

void ComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const {
    if (auto *comboBox = dynamic_cast<QComboBox *>(editor)) {
        model->setData(index, comboBox->currentText(), Qt::EditRole);
    }
}

void ComboBoxItemDelegate::updateEditorGeometry(QWidget *editor,
                                                const QStyleOptionViewItem &option,
                                                const QModelIndex &/*index*/) const {
    editor->setGeometry(option.rect);
}

void ComboBoxItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                                 const QModelIndex &index) const {
    if (index.column() == 4) {
        QStyleOptionComboBox comboBoxStyleOption;
        comboBoxStyleOption.state = option.state;
        comboBoxStyleOption.rect = option.rect;
        comboBoxStyleOption.currentText = index.data(Qt::EditRole).toString();

        QApplication::style()->drawComplexControl(QStyle::CC_ComboBox, &comboBoxStyleOption, painter, 0);
        QApplication::style()->drawControl(QStyle::CE_ComboBoxLabel, &comboBoxStyleOption, painter, 0);

        return;
    }

    QStyledItemDelegate::paint(painter, option, index);
}
