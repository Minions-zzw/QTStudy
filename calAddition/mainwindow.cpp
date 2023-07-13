#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QMessageBox> //消息提示框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_1->setValidator(new QIntValidator(ui->lineEdit_1)); //设置只能输入整数
    ui->lineEdit_2->setValidator(new QIntValidator(ui->lineEdit_2));//设置只能输入整数
    this->connect(ui->lineEdit_2,SIGNAL(returnPressed()),this,SLOT(calShlot())); //设置信号量和槽
    this->connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(calShlot())); //设置信号量和槽

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::calShlot(){
    qint32 a = 0;//声明两个整数用于加法计算
    qint32 b = 0;
    a = ui->lineEdit_1->text().toInt();//获取两个字符，并将其转化为int类型
    b = ui->lineEdit_2->text().toInt();
    switch (ui->comboBox->currentIndex()) { //判断是加减乘除的哪种情况
        case 0:
            ui->resultText->setText(QString::number(a+b));
            break;
        case 1:
            ui->resultText->setText(QString::number(a-b));
            break;
        case 2:
            ui->resultText->setText(QString::number(a*b));
            break;
        case 3:
            if(0 == b) {
                QMessageBox::information(this,"Result","The divisor cannot be 0!");
                return;
            }
            ui->resultText->setText(QString::number(((float)a/b))); //将int转换为float类型，适应除法
    }
    //调用静态方法
    QMessageBox::information(this,"Result",ui->resultText->text());
//    QMessageBox::StandardButton QMessageBox::information(QWidget *parent, const QString &title, const QString &text, QMessageBox::StandardButtons buttons = Ok, QMessageBox::StandardButton defaultButton = NoButton)
//    if(ui->comboBox->currentIndex() == 1) ui->resultText->setText(QString::number(a+b));
//    if(ui->comboBox->currentIndex() == 2) ui->resultText->setText(QString::number(a-b));
//    if(ui->comboBox->currentIndex() == 3) ui->resultText->setText(QString::number(a*b));
//    if(ui->comboBox->currentIndex() == 4) ui->resultText->setText(QString::number(a/b));

}
void MainWindow::on_pushButton_clicked(){

}
