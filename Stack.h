// Yağız Can Aslan 22001943

// Stack Class modified from Lecture Slides (Slide 10)
#include <string>
using namespace std;

typedef char StackItem;

class Stack{
    public:
        Stack();
        Stack( const Stack& otherStack);
        ~Stack();
        
        bool isEmpty() const;
        bool push( StackItem newItem);
        bool pop();
        bool pop( StackItem& stackTop);
        bool getTop( StackItem& stackTop) const;

    private:
        struct StackNode {
            StackItem item;
            StackNode* next;
        };

        StackNode *topNode;
};