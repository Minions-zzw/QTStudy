#include "widget.h"
#include "ui_widget.h"
#include <QProcess>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMaximumSize(327,108);
    this->setMinimumSize(327,108);
    QObject::connect(ui->cmdLineEdit,SIGNAL(returnPressed()),this,SLOT(on_submitButton_clicked()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_submitButton_clicked()
{
    QProcess *process = new QProcess();
    QString startProgram = ui->cmdLineEdit->text();
//    while(startProgram.at(startProgram.size()-1).isSpace()) startProgram.chop(1); //使用循环方法删除掉末尾的空格
//    while(startProgram.at(startProgram.size()-1) == ' ') startProgram.chop(1);
//    ui->cmdLineEdit->setText(startProgram.trimmed()); //使用trimmed方法删除字符串开头和末尾的空格
    process->start(startProgram.trimmed()); //启动一个程序
    ui->cmdLineEdit->clear();//情况字符串
    this->close();//关闭程序

//    QProcess *myProcess = new QProcess(parent);
//    myProcess->start(program, arguments);

}
