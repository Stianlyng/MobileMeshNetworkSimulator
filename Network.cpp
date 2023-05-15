#include <vector>
#include "Node.h"
#include "Message.h"
#include "Network.h"


class Network {
private:
    std::vector<Node*> nodes; // Liste over noder i nettverket. Hver node representerer en enhet i nettverket.
    std::vector<Message*> messages; // Kø av meldinger som skal overføres. Dette representerer dataene som skal sendes over nettverket.

public:
    // Legg til en node i nettverket
    void addNode(Node* node) {
        nodes.push_back(node); // legger til en ny node i nettverket. Noden blir lagt til i listen over noder.
    }

    // Fjern en node fra nettverket
    void removeNode(Node* node) {
        nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end()); // fjerner en node fra nettverket. Den fjerner noden fra listen over noder.
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
            Node* destination = message->getDestination(); // For hver melding i køen, hent destinasjonsnoden.
            destination->receiveMessage(message); // La destinasjonsnoden motta meldingen. Dette er en forenkling. I et ekte nettverk, ville meldingen sannsynligvis måtte passere gjennom flere noder for å nå sin destinasjon.
        }
        messages.clear(); // Tøm meldingskøen etter at alle meldinger er overført. Dette representerer slutten på en "runde" med meldingsoverføring.
    }

    // Performace metrics

    double computeThroughput() {
        // beregner troughput i nettverket( et mål på hvor mye data som kan sendes gjennom nettverket i en gitt tidsperiode)
    }

    double computeLatency() {
        // beregner latency i nettverket ( tiden det tar for en melding å reise fra kilden til destinasjonen)
    }

    double computePacketLoss() {
        // beregner packet loss i nettverket ( mål på hvor mange meldinger som går tapt under overføring og aldri når destinasjonen)
    }
};