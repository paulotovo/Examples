#include <QMainWindow>
#include <QApplication>
#include <QTableWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow *w = new QMainWindow();

    QTableWidget* table = new QTableWidget();
    table->setFixedSize(300,300);

    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Highlight,Qt::cyan);
    table->setPalette(*palette);

    table->setRowCount(2);
    table->setColumnCount(3);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    //Set Header Label Texts Here
    table->setHorizontalHeaderLabels(QString("HEADER 1;HEADER 2;HEADER 3").split(";"));

    //Add Table items here
    table->setItem(0,0,new QTableWidgetItem("ITEM 1_1"));
    table->setItem(0,1,new QTableWidgetItem("ITEM 1_2"));
    table->setItem(0,2,new QTableWidgetItem("ITEM 1_3"));

    table->setItem(1,0,new QTableWidgetItem("ITEM 2_1"));
    table->setItem(1,1,new QTableWidgetItem("ITEM 2_2"));
    table->setItem(1,2,new QTableWidgetItem("ITEM 2_3"));

    w->setCentralWidget(table);

    w->show();

    return a.exec();
}
