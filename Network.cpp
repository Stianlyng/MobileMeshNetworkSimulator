#include <vector>
#include "Node.h"
#include "Message.h"
#include "Network.h"


class Network {
private:
    std::vector<Node*> nodes; // Liste over noder i nettverket. Hver node representerer en enhet i nettverket.
    std::vector<Message*> messages; // Kø av meldinger som skal overføres. Dette representerer dataene som skal sendes over nettverket.

	// todo; temp? fjernes når routing er implementert??
	// må være en singleton, for å få tilgang fra node klassen
	Network() {} // fjern
	static Network* instance; //fjern

public:

	// todo; temp? fjernes når routing er implementert??
    static Network* getInstance() {
        if (!instance) {
            instance = new Network();
        }
        return instance;
    }

    // Legg til en node i nettverket
    void addNode(Node* node) {
        nodes.push_back(node); // legger til en ny node i nettverket. Noden blir lagt til i listen over noder.
    }

    // Fjern en node fra nettverket
    void removeNode(Node* node) {
        nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end()); // fjerner en node fra nettverket. Den fjerner noden fra listen over noder.
    }

	// temp; legger til en melding i meldingskøen, fjernes når routing er implementert
	void addMessage(Message* message) {
	    messages.push_back(message);
	}
    // Oppdater tilstanden i nettverket
    void update() {
        // Oppdater posisjonene til alle noder
        for (Node* node : nodes) {
            node->updatePosition(); // For hver node i nettverket, oppdater posisjonen. Dette kan brukes i en simulering der noder beveger seg over tid.
        }

        // Håndter meldingsoverføring
		// todo; implementer en routing algoritme, f.eks. AODV eller DSR
		for (Message* message : messages) {
    	    Node* source = message->getSource();
    	    for (Node* node : nodes) {
    	        if (distance(source, node) <= source->getRange()) {
    	            node->receiveMessage(message);
    	        }
    	    }
    	}
        messages.clear(); // Tøm meldingskøen etter at alle meldinger er overført. Dette representerer slutten på en "runde" med meldingsoverføring.
    }

	// todo; temp? fjernes når routing er implementert??
	// Beregn avstanden mellom to noder
	double distance(Node* node1, Node* node2) {
	    double xDiff = node1->getX() - node2->getX();
	    double yDiff = node1->getY() - node2->getY();
	    return sqrt(xDiff * xDiff + yDiff * yDiff);
	}

    // Performace metrics

    double computeThroughput() {
        // beregner troughput i nettverket( et mål på hvor mye data som kan sendes gjennom nettverket i en gitt tidsperiode)
		// dummy
		return 0.0;
    }

    double computeLatency() {
        // beregner latency i nettverket ( tiden det tar for en melding å reise fra kilden til destinasjonen)
		// dummy
		return 0.0;
    }

    double computePacketLoss() {
        // beregner packet loss i nettverket ( mål på hvor mange meldinger som går tapt under overføring og aldri når destinasjonen)
		// dummy
		return 0.0;
    }
};