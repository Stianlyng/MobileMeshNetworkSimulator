#include "RREP.h"

RREP::RREP(int sourceId, int destinationId, int sequenceNumber, int hopCount)
    : sourceId(sourceId), destinationId(destinationId), sequenceNumber(sequenceNumber), hopCount(hopCount) {}

int RREP::getSourceId() { return sourceId; }
int RREP::getDestinationId() { return destinationId; }
int RREP::getSequenceNumber() { return sequenceNumber; }
int RREP::getHopCount() { return hopCount; }