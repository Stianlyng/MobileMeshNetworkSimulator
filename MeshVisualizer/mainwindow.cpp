#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);

    // Create some nodes
    for (int i = 0; i < 10; ++i) {
        QGraphicsEllipseItem* node = scene->addEllipse(i * 50, 0, 20, 20);
        node->setBrush(QBrush(Qt::blue));
    }

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
