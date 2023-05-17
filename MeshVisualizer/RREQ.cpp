
#include "RREQ.h"

RREQ::RREQ(int sourceId, int destinationId, int broadcastId, int sequenceNumber)
    : sourceId(sourceId), destinationId(destinationId), broadcastId(broadcastId), sequenceNumber(sequenceNumber), hopCount(0) {}

int RREQ::getSourceId() { return sourceId; }
int RREQ::getDestinationId() { return destinationId; }
int RREQ::getBroadcastId() { return broadcastId; }
int RREQ::getSequenceNumber() { return sequenceNumber; }
int RREQ::getHopCount() { return hopCount; }

void RREQ::incrementHopCount() { hopCount++; }