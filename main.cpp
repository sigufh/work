// main.cpp
#include <QApplication>
#include "mainwidget.h"
#include"insertStu.h"
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MainWidget widget;
    widget.show();

    return app.exec();
}
//int main()
//{
//	Student stu{ 123467,"李毅","12班" };
//	StudentManager::GetInstance()->insert_student(stu);
//}