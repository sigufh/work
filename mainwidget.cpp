// mainwidget.cpp
#include "mainwidget.h"
#include"insertStu.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLibrary>
#include <QDebug>
#include<Qstring>
#include<iostream>
#include <QCoreApplication>
#include <QPlainTextEdit>

MainWidget::MainWidget(QWidget* parent)
    : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* idLabel = new QLabel("Student ID:");
    idEdit = new QLineEdit(this);

    QLabel* nameLabel = new QLabel("Student Name:");
    nameEdit = new QLineEdit(this);

    QLabel* classLabel = new QLabel("Class ID:");
    classEdit = new QLineEdit(this);

    QPushButton* registerButton = new QPushButton("Register", this);
    connect(registerButton, SIGNAL(clicked()), this, SLOT(registerStudent()));

    QLabel* idDisplayLabel = new QLabel("Input ID:");
    QLabel* nameDisplayLabel = new QLabel("Input Name:");
    QLabel* classDisplayLabel = new QLabel("Input Class:");

    layout->addWidget(idLabel);
    layout->addWidget(idEdit);
    layout->addWidget(nameLabel);
    layout->addWidget(nameEdit);
    layout->addWidget(classLabel);
    layout->addWidget(classEdit);
    layout->addWidget(registerButton);

    // 添加用于显示输入值的 QLabel
    layout->addWidget(idDisplayLabel);
    layout->addWidget(nameDisplayLabel);
    layout->addWidget(classDisplayLabel);

    // 保存 QLabel 的指针，以便在 registerStudent() 中更新显示的值
    displayLabels.append(idDisplayLabel);
    displayLabels.append(nameDisplayLabel);
    displayLabels.append(classDisplayLabel);
}

void MainWidget::registerStudent() {
     /*获取输入值*/
    //Student student;

    long student_id = idEdit->text().toLong();
    string student_name = string(nameEdit->text().toLocal8Bit());
    string class_id = string(classEdit->text().toLocal8Bit());

    // 更新显示输入值的 QLabel
    displayLabels.at(0)->setText("Input ID: " + QString::number(student_id));
    displayLabels.at(1)->setText("Input Name: " + nameEdit->text());
    displayLabels.at(2)->setText("Input Class: " + QString::fromStdString(class_id));

    Student* stu = new Student;
    stu->student_id = idEdit->text().toLong();
    //long student_id = idEdit->text().toLong();
    //string student_name = nameEdit->text().toStdString();
    //string class_id = classEdit->text().toStdString();
    //long student_id = 142353;
    //string student_name = "刘毅";
    //string class_id = "11班";
    //Student stu1;
    //stu1.student_id = student.student_id;
    //stu1.student_name = student.student_name.toStdString();
    //stu1.class_id = student.class_id.toStdString();
    Student student{ stu->student_id,student_name,class_id,"0",0,"0","0",0,"0"};
  
    StudentManager::GetInstance()->insert_student(student);
    qDebug() << student.student_id;
    qDebug() << idEdit->text().toLong();
    if (StudentManager::GetInstance()->insert_student(student)) {
        qDebug() << "seccess";
    }
    else {
        qDebug() << "fail";
    }
    qDebug() << student.student_id << StudentManager::GetInstance()->insert_student(student);
    delete stu;
}