#ifndef RREQ_H
#define RREQ_H

class RREQ {
private:
    int sourceId; 
    int destinationId; 
    int broadcastId; 
    int sequenceNumber; 
    int hopCount; 

public:

    RREQ(int sourceId, int destinationId, int broadcastId, int sequenceNumber);
    
    int getSourceId();
    int getDestinationId();
    int getBroadcastId();
    int getSequenceNumber();
    int getHopCount();

    void incrementHopCount();
};

#endif /* RREQ_H */