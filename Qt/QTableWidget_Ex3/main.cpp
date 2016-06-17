#include <QMainWindow>
#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow *w = new QMainWindow();

    w->setWindowTitle(QString::fromUtf8("QTableWidget Set Cell Color"));
    w->resize(400, 250);

    QTableWidget* table = new QTableWidget();

    //Set table row count 1 and column count 3
    table->setRowCount(1);
    table->setColumnCount(3);

    table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    //Set Header Label Texts Here
    table->setHorizontalHeaderLabels(QString("HEADER 1;HEADER 2;HEADER 3").split(";"));


    //Add Table items here
    table->setItem(0,0,new QTableWidgetItem("ITEM 1"));
    table->setItem(0,1,new QTableWidgetItem("ITEM 2"));
    table->setItem(0,2,new QTableWidgetItem("ITEM 3"));

    //Color Table Cells Here
    table->item(0,0)->setBackgroundColor(Qt::red);
    table->item(0,1)->setBackgroundColor(Qt::green);
    table->item(0,2)->setBackgroundColor(Qt::blue);

    w->setCentralWidget(table);
    w->show();

    return a.exec();
}
