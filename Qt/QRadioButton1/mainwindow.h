#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnOp1_clicked();

    void on_btnOp2_clicked();

    void on_btnOp3_clicked();

    void on_btnOp4_clicked();

    void on_btnReset_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
