// mainwidget.h
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

// 定义结构体
struct _Student {
    int student_id;
    QString student_name;
    QString class_id;
};

class MainWidget : public QWidget {
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);

private slots:
    void registerStudent();

private:
    QLineEdit *idEdit;
    QLineEdit *nameEdit;
    QLineEdit *classEdit;

    QVector<QLabel*> displayLabels;
};

#endif // MAINWIDGET_H

