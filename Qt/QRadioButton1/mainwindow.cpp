#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOp1_clicked()
{
  ui->rb1->setChecked(true);
}

void MainWindow::on_btnOp2_clicked()
{
  ui->rb2->setChecked(true);
}

void MainWindow::on_btnOp3_clicked()
{
  ui->rb3->setChecked(true);
}

void MainWindow::on_btnOp4_clicked()
{
  ui->rb4->setChecked(true);
}

void MainWindow::on_btnReset_clicked()
{
  if(ui->rb1->isChecked())
  {
     QMessageBox::warning(0,"Warning","Entrou na checagem RB1");
     ui->rb1->setAutoExclusive(false);
     ui->rb1->setChecked(false);
     ui->rb1->setAutoExclusive(true);
  }

  if(ui->rb2->isChecked())
  {
     QMessageBox::warning(0,"Warning","Entrou na checagem RB2");
     ui->rb2->setChecked(false);
  }

  if(ui->rb3->isChecked())
  {
     QMessageBox::warning(0,"Warning","Entrou na checagem RB3");
     ui->rb3->setChecked(false);
  }

  if(ui->rb4->isChecked())
  {
     QMessageBox::warning(0,"Warning","Entrou na checagem RB4");
     ui->rb4->setChecked(false);
  }
}
