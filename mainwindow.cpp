#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree=new Tree;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->InputEdit->text()!=""){
        tree->add(ui->InputEdit->text().toDouble());
    }
ui->InputEdit->clear();

ui->textEdit->clear();
tree->print(ui->textEdit);

}

void MainWindow::on_pushButton_2_clicked()
{
tree->balanc();
ui->textEdit->clear();
tree->print(ui->textEdit);


}


void MainWindow::on_clrBtn_clicked()
{
    tree->clear();
    ui->textEdit->clear();

}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if (checked)
        ui->InputEdit->setText("fasaf");

}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(checked)ui->InputEdit->setText("f123");
}
