#include <QApplication>
#include "mainwindow.h"
#include "Network.h"
#include "Node.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Network instance
    Network* network = Network::getInstance();

    // Add nodes to network
    // Note: The position, range, speed, and direction values are just examples. You can replace them with actual values.
    Node* node1 = new Node(1, 50, 50, 10, 1, 0);
    Node* node2 = new Node(2, 100, 100, 10, 1, 0);
    Node* node3 = new Node(3, 150, 150, 10, 1, 0);
    Node* node4 = new Node(4, 200, 200, 10, 1, 0);
    Node* node5 = new Node(5, 250, 250, 10, 1, 0);
    Node* node6 = new Node(6, 300, 300, 10, 1, 0);
    Node* node7 = new Node(7, 350, 350, 10, 1, 0);
    Node* node8 = new Node(8, 400, 400, 10, 1, 0);
    Node* node9 = new Node(9, 450, 450, 10, 1, 0);
    Node* node10 = new Node(10, 500, 500, 10, 1, 0);
    Node* node11 = new Node(11, 550, 550, 10, 1, 0);
    Node* node12 = new Node(12, 600, 600, 10, 1, 0);
    Node* node13 = new Node(13, 650, 650, 10, 1, 0);

    network->addNode(node1);
    network->addNode(node2);
    network->addNode(node3);
    network->addNode(node4);
    network->addNode(node5);
    network->addNode(node6);
    network->addNode(node7);
    network->addNode(node8);
    network->addNode(node9);
    network->addNode(node10);
    network->addNode(node11);
    network->addNode(node12);
    network->addNode(node13);
    

    // Add neighbors to the nodes
    node1->addNeighbor(node2);
    node2->addNeighbor(node3);
    node3->addNeighbor(node4);
    node4->addNeighbor(node5);
    node5->addNeighbor(node6);
    node6->addNeighbor(node7);
    node7->addNeighbor(node8);
    node8->addNeighbor(node9);
    node9->addNeighbor(node10);
    node10->addNeighbor(node11);
    node11->addNeighbor(node12);
    node12->addNeighbor(node13);
    


    MainWindow w;

    // Refresh the network visualization
    w.refreshNetworkVisualization();
    w.show();
    return a.exec();
}