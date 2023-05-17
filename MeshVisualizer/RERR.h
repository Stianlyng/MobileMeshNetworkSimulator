#ifndef RERR_H
#define RERR_H

class RERR {
private:
    int sourceId; 
    int brokenNodeId; 
    int destinationId; 

public:
    RERR(int sourceId, int brokenNodeId, int destinationId);

    int getSourceId();
    int getBrokenNodeId();
    int getDestinationId();
};

#endif /* RERR_H */