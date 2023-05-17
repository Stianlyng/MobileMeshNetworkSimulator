
#include "RERR.h"

RERR::RERR(int sourceId, int brokenNodeId, int destinationId)
    : sourceId(sourceId), brokenNodeId(brokenNodeId), destinationId(destinationId) {}

int RERR::getSourceId() { return sourceId; }
int RERR::getBrokenNodeId() { return brokenNodeId; }
int RERR::getDestinationId() { return destinationId; }