#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Network.h"
#include "NodeItem.h"   
#include <QGraphicsLineItem>
#include <QLabel>  

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setInteractive(true);

    infoLabel = new QLabel(this);  
    ui->verticalLayout->addWidget(infoLabel);  

    refreshNetworkVisualization();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInfoLabelText(const QString& text) {
    infoLabel->setText(text);
}

void MainWindow::refreshNetworkVisualization() {

    scene->clear();

    // henter nodene fra Network
    Network* network = Network::getInstance();
    std::vector<Node*> nodes = network->getNodes();

    // tegner nodene
    for (Node* node : nodes) {
        NodeItem* nodeItem = new NodeItem(node, this); // Change here
        scene->addItem(nodeItem); // Add the custom NodeItem to the scene
    }

    // tegner forbindelsene mellom nodene
    for (Node* node : nodes) {
        std::vector<Node*> neighbors = node->getNeighbors();
        for (Node* neighbor : neighbors) {
            QGraphicsLineItem* connection = scene->addLine(node->getX(), node->getY(), neighbor->getX(), neighbor->getY());
            connection->setPen(QPen(Qt::black, 2));
        }
    }
}