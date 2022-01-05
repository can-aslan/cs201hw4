// Yağız Can Aslan 22001943

#include <string>
#include "AlgebraicExpression.h"
#include "Stack.h"
using namespace std;

bool precedence( const char a, const char b ) { // Returns true if a has precedence over/equal to b
    switch (a)
    {
    case '+':
        switch (b)
        {
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '/':
            return false;
            break;
        case '*':
            return false;
            break;
        }
        break;
    case '-':
        switch (b)
        {
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '/':
            return false;
            break;
        case '*':
            return false;
            break;
        }
        break;
    case '/':
        switch (b)
        {
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '/':
            return true;
            break;
        case '*':
            return true;
            break;
        }
        break;
    case '*':
        switch (b)
        {
        case '+':
            return true;
            break;
        case '-':
            return true;
            break;
        case '/':
            return true;
            break;
        case '*':
            return true;
            break;
        }
        break;
    }
}

string infix2prefix( const string exp ) {

}

string infix2postfix( const string exp ) {
    Stack stck;
    string postfix;
    int i = 0;

    while ( exp[i] != '\0' ) {
        switch ( exp[i] )
        {
            case '(':
                stck.push(exp[i]);
                break;
            case ')':
                char stackTop;
                stck.getTop(stackTop);

                while ( stackTop != '(' ) {
                    postfix += stackTop;
                    stck.pop(stackTop);
                }

                stck.pop();
                break;
            case ('+' || '-' || '*' || '/'):

                break;
            default /* Everything other than the charaters above are thought as operands */:
                postfix += exp[i];
                break;
        }
    }

    return postfix;
}

string prefix2infix( const string exp ) {

}

string prefix2postfix( const string exp ) {

}

string postfix2infix( const string exp ) {

}

string postfix2prefix( const string exp ) {

}

double evaluateInfix( const string exp ) {

}

double evaluatePrefix( const string exp ) {

}

double evaluatePostfix( const string exp ) {

}
