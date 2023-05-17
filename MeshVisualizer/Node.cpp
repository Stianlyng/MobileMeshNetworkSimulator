// Node-klassen representerer en node i et nettverk. Hver node har en unik identifikator, en posisjon (x, y),
// en kommunikasjonsrekkevidde, en bevegelseshastighet, en bevegelsesretning og en liste over nabo-noder.
#include "Node.h"
#include "Network.h"
#include <iostream>

// Konstruktør: Initialiserer en ny instans av Node-klassen
Node::Node(int id, double x, double y, double range, double speed, double direction)
    : id(id), x(x), y(y), range(range), speed(speed), direction(direction) {}

// Getters 
int Node::getId() { return id; }
double Node::getX() { return x; }
double Node::getY() { return y; }
double Node::getRange() { return range; }
double Node::getSpeed() { return speed; }
double Node::getDirection() { return direction; }
std::vector<Node*> Node::getNeighbors() { return neighbors; }


// Setters
void Node::setX(double newX) { x = newX; }
void Node::setY(double newY) { y = newY; }
void Node::setRange(double newRange) { range = newRange; }
void Node::setSpeed(double newSpeed) { speed = newSpeed; }
void Node::setDirection(double newDirection) { direction = newDirection; }


// Oppdater posisjon basert på hastighet og retning: 
// Denne funksjonen oppdaterer nodens posisjon ved å flytte den i dens nåværende retning med dens nåværende hastighet
void Node::updatePosition() {
    x += speed * cos(direction);
    y += speed * sin(direction);
}

// Legg til en nabo: Denne funksjonen legger til en node i listen over naboer
void Node::addNeighbor(Node* neighbor) {
    neighbors.push_back(neighbor);
}

// Fjern en nabo: Denne funksjonen fjerner en node fra listen over naboer
void Node::removeNeighbor(Node* neighbor) {
    neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), neighbor), neighbors.end());
}

// Sender en melding til alle naboer innenfor rekkevidde. Fjern når routing er implementert
void Node::sendMessage(Message* message) {
    Network::getInstance()->addMessage(message);
}

// Mottar en melding fra naboer innenfor rekkevidden. Fjern når routing er implementert
void Node::receiveMessage(Message* message) {
    std::cout << "Node " << id << " received message: " << message->getData() << std::endl;
}