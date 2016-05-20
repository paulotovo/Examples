#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Cria o quadrado vermelho
    QPixmap pixmap(500,500);
    pixmap.fill(QColor("red"));
    QIcon redIcon(pixmap);

    // Carrega uma imagem no tab
    QImage img("C:\\Users\\paulo\\Documents\\testTab\\img.png",0);
    QPixmap imgPixmap = QPixmap::fromImage(img);
    QIcon imgIcon(imgPixmap);

    QSize size(120, 120);
    // Seta o tamanho o icone(quadrado vermelho) que irá ser criado dentro da tab
    ui->tabWidget->tabBar()->setIconSize(size);
    // Seta o quadrado vermelho como icone nas tabs 1 e 2
    ui->tabWidget->tabBar()->setTabIcon(0,redIcon);
    ui->tabWidget->tabBar()->setTabIcon(1,imgIcon);
}

MainWindow::~MainWindow()
{
    delete ui;
}
