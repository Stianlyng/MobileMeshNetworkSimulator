#include "Route.h"

Route::Route(int destinationId, Node* nextHop, int hopCount)
    : destinationId(destinationId), nextHop(nextHop), hopCount(hopCount) {}

int Route::getDestinationId() { return destinationId; }
Node* Route::getNextHop() { return nextHop; }
int Route::getHopCount() { return hopCount; }

void Route::setNextHop(Node* newNextHop) { nextHop = newNextHop; }
void Route::setHopCount(int newHopCount) { hopCount = newHopCount; }