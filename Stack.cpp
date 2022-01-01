// Yağız Can Aslan 22001943

// Stack Class modified from Lecture Slides (Slide 10)
#include <string>
#include "Stack.h"
using namespace std;

Stack::Stack() : topNode(NULL) {}

Stack::Stack( const Stack& aStack ){
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

bool Stack::isEmpty() const {
    return topNode == NULL;
}

bool Stack::push( StackItem newItem ) {
   StackNode *newNode = new StackNode;

   newNode->item = newItem;

   newNode->next = topNode;
   topNode = newNode;

   return true;
}

bool Stack::pop() {
    if ( isEmpty() ) {
        return false;
    }
    else {   
        StackNode *temp = topNode;
        topNode = topNode->next;

        temp->next = NULL;
        delete temp;

        return true;
    }
}