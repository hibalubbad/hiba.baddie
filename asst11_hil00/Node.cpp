#include <iostream>
#include <string>
#include "Node.h"

Node::Node()
{
    elem = "";
    next = NULL;
}

Node::Node(string data){
    elem = data;
    next = NULL;
}
