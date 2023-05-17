#include "Network.h"
#include <cmath>

Network* Network::instance = nullptr;

Network::Network() {}

// todo; temp? fjernes når routing er implementert??
Network* Network::getInstance() {
    if (!instance) {
        instance = new Network();
    }
    return instance;
}

void Network::addNode(Node* node) {
	// legger til en ny node i nettverket. Noden blir lagt til i listen over noder.
    nodes.push_back(node); 
}

// liste over alle noder i nettverket. Brukes av GUI for å visualisere nettverket.
std::vector<Node*> Network::getNodes() const {
    return nodes;
}

void Network::removeNode(Node* node) {
	// fjerner en node fra nettverket. Den fjerner noden fra listen over noder.
    nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end()); 
}



void Network::addMessage(Message* message) {
	// temp; legger til en melding i meldingskøen, fjernes når routing er implementert
    messages.push_back(message);
}

// Oppdater tilstanden i nettverket
void Network::update() {

	// For hver node i nettverket, oppdater posisjonen.
	// Dette kan brukes i en simulering der noder beveger seg over tid.
    for (Node* node : nodes) {
        node->updatePosition();
    }

    // Håndter meldingsoverføring. Fjern når routing er implementert.
    for (Message* message : messages) {
        Node* source = message->getSource();
        for (Node* node : nodes) {
            if (distance(source, node) <= source->getRange()) {
                node->receiveMessage(message);
            }
        }
    }
	// Tøm meldingskøen etter at alle meldinger er overført. Dette representerer slutten på en "runde" med meldingsoverføring.
    messages.clear();
}

// todo; temp? fjernes når routing er implementert??
// Beregn avstanden mellom to noder
double Network::distance(Node* node1, Node* node2) {
    double xDiff = node1->getX() - node2->getX();
    double yDiff = node1->getY() - node2->getY();
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

// Performace metrics

// beregner troughput i nettverket( et mål på hvor mye data som kan sendes gjennom nettverket i en gitt tidsperiode)
double Network::computeThroughput() {
    return 0.0;
}


// beregner latency i nettverket ( tiden det tar for en melding å reise fra kilden til destinasjonen)
double Network::computeLatency() {
    return 0.0;
}


// beregner packet loss i nettverket ( mål på hvor mange meldinger som går tapt under overføring og aldri når destinasjonen)
double Network::computePacketLoss() {
    return 0.0;
}