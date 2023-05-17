#ifndef RREP_H
#define RREP_H

class RREP {
private:
    int sourceId; 
    int destinationId; 
    int sequenceNumber; 
    int hopCount; 

public:

    RREP(int sourceId, int destinationId, int sequenceNumber, int hopCount);

    int getSourceId();
    int getDestinationId();
    int getSequenceNumber();
    int getHopCount();
};

#endif /* RREP_H */