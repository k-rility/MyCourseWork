#ifndef WINDOW_BASE_HPP_
#define WINDOW_BASE_HPP_

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QSqlQueryModel>
#include <QTableView>


class window_base : public QWidget {
Q_OBJECT
public:
    explicit window_base(QWidget *parent = nullptr);

    virtual ~window_base() noexcept override;

    virtual void setupModel(const QString &, const QStringList &);

protected:

    QSqlQueryModel *getModel() const;

private:
    QSqlQueryModel *model;
};


#endif // WINDOW_BASE_HPP_
