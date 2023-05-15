#include "Node.h"
#include "Message.h"
#include "Network.h"

int main() {
    // Create nodes
    Node* node1 = new Node(1, 0, 0, 10, 0, 0);
    Node* node2 = new Node(2, 5, 0, 10, 0, 0);
    Node* node3 = new Node(3, 10, 0, 10, 0, 0);

    // Add nodes to network
    Network* network = Network::getInstance();
    network->addNode(node1);
    network->addNode(node2);
    network->addNode(node3);

    // Create messages
    Message* message1 = new Message(node1, node2, "Hello from Node 1");
    Message* message2 = new Message(node2, node3, "Hello from Node 2");

    // Send messages
    node1->sendMessage(message1);
    node2->sendMessage(message2);

    // Update network
    network->update();

    // Cleanup
    delete message1;
    delete message2;
    delete node1;
    delete node2;
    delete node3;

    return 0;
}