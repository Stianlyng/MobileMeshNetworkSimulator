#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

// Node-klassen representerer en node i et nettverk. Hver node har en unik identifikator, en posisjon (x, y),
// en kommunikasjonsrekkevidde, en bevegelseshastighet, en bevegelsesretning og en liste over nabo-noder.
class Node {
private:
    int id; // Unik identifikator for noden
    double x, y; // Posisjonen til noden i et 2D-rom
    double range; // Kommunikasjonsrekkevidden til noden, bestemmer hvor langt den kan sende/motta meldinger
    double speed; // Hastigheten som noden beveger seg med
    double direction; // Retningen som noden beveger seg i, representert i radianer
    std::vector<Node*> neighbors; // Liste over nabo-noder innenfor kommunikasjonsrekkevidde

public:
    // Konstruktør: Initialiserer en ny instans av Node-klassen
    Node(int id, double x, double y, double range, double speed, double direction)
        : id(id), x(x), y(y), range(range), speed(speed), direction(direction) {}

    // Getters 
    int getId() { return id; }
    double getX() { return x; }
    double getY() { return y; }
    double getRange() { return range; }
    double getSpeed() { return speed; }
    double getDirection() { return direction; }
    std::vector<Node*> getNeighbors() { return neighbors; }

    // Setters
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    void setRange(double newRange) { range = newRange; }
    void setSpeed(double newSpeed) { speed = newSpeed; }
    void setDirection(double newDirection) { direction = newDirection; }

    // Oppdater posisjon basert på hastighet og retning: 
    // Denne funksjonen oppdaterer nodens posisjon ved å flytte den i dens nåværende retning med dens nåværende hastighet
    void updatePosition() {
        x += speed * cos(direction);
        y += speed * sin(direction);
    }

    // Legg til en nabo: Denne funksjonen legger til en node i listen over naboer
    void addNeighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }

    // Fjern en nabo: Denne funksjonen fjerner en node fra listen over naboer
    void removeNeighbor(Node* neighbor) {
        neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), neighbor), neighbors.end());
    }

    // Sender en melding til alle naboer innenfor rekkevidde.
    //void sendMessage(Message* message) {
    //    // Todo; 
    //}

    // Mottar en melding fra naboer innenfor rekkevidden.
    //void receiveMessage(Message* message) {
    //    // Todo;
    //}

};