// Yağız Can Aslan 22001943

#include <string>
#include "Stack.h"
using namespace std;

Stack::Stack() : topNode(NULL) {}

Stack::Stack(const Stack& aStack){
    if (aStack.topNode == NULL) {
        topNode = NULL;  // original stack is empty​
    }
    else {
        // Copy the first node​
        topNode = new StackNode;
        topNode->item = aStack.topNode->item;

        // Copy the rest of the nodes
        StackNode *newNode = topNode;
        for ( StackNode *origPtr = aStack.topNode->next; origPtr != NULL; origPtr = origPtr->next ) {
            newNode->next = new StackNode;
            newNode = newNode->next;
            newNode->item = origPtr->item;
        }

        newNode->next = NULL;
    }
}

Stack::~Stack() {
    while ( !isEmpty() ) {
        pop();
    }
}