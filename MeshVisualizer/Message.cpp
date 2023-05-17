#include "Message.h"

Message::Message(Node* source, Node* destination, const std::string& data)
    : source(source), destination(destination), data(data) {}

Node* Message::getSource() { 
    return source; 
}

Node* Message::getDestination() { 
    return destination; 
}

std::string Message::getData() { 
    return data; 
}
