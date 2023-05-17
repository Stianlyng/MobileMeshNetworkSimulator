#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Network.h"
#include "NodeItem.h"   // Include this
#include <QGraphicsLineItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setInteractive(true);

    refreshNetworkVisualization();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshNetworkVisualization() {
    // Clear the current visualization
    scene->clear();

    // Get the current state of the network
    Network* network = Network::getInstance();
    std::vector<Node*> nodes = network->getNodes();

    // Draw each node
    for (Node* node : nodes) {
        NodeItem* nodeItem = new NodeItem(node); // Change here
        scene->addItem(nodeItem); // Add the custom NodeItem to the scene
    }

    // Draw connections between nodes
    for (Node* node : nodes) {
        std::vector<Node*> neighbors = node->getNeighbors();
        for (Node* neighbor : neighbors) {
            QGraphicsLineItem* connection = scene->addLine(node->getX(), node->getY(), neighbor->getX(), neighbor->getY());
            connection->setPen(QPen(Qt::black, 2));
        }
    }
}