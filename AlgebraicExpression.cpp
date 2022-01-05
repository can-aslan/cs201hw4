// Yağız Can Aslan 22001943

#include <string>
#include "AlgebraicExpression.h"
#include "Stack.h"
using namespace std;

string toStringFromChar( char a ) {
    string result;
    result += a;
    return result;
}

char toCharFromString( string a ) {
    return a[0];
}

bool isOperator( const char a ) {
    if ( a == '+' || a == '-' || a == '*' || a == '/' ) {
        return true;
    }
    else {
        return false;
    }
}

bool isOperand( const char a ) {
    return (!isOperator(a) && a != '(' && a != ')' );
}

bool precedence( const char a, const char b ) { // Returns true if a has precedence greater than/equal to b
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
            return true;
            break;
        case '*':
            return true;
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
            return true;
            break;
        case '*':
            return true;
            break;
        }
        break;
    case '/':
        switch (b)
        {
        case '+':
            return false;
            break;
        case '-':
            return false;
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
            return false;
            break;
        case '-':
            return false;
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

    return false;
}

string infix2prefix( const string exp ) {
    return NULL;
}

string infix2postfix( const string exp ) {
    Stack stck;
    string postfix = "";
    char topChar;
    string topString;
    int i = 0;

    while ( exp[i] != '\0' ) {
        if ( isOperand(exp[i]) || exp[i] == ' ' ) {
            postfix = postfix + exp[i];
        }
        else if ( exp[i] == '(' ) {
            stck.push( toStringFromChar(exp[i]));
        }
        else if ( exp[i] == ')' ) {
            int first = 1;
            stck.getTop( topString);

            while ( topString != "(" ) {
                postfix += topString;

                if ( first == 1 ) {
                    stck.pop();
                    first = 0;
                }

                stck.pop( topString);
            }
            stck.pop();
        }
        else if ( isOperator(exp[i]) ) {
            int first = 1;
            stck.getTop(topString);

            while ( !stck.isEmpty() && precedence(exp[i], toCharFromString(topString)) ) {
                postfix += topString;

                if ( first == 1 ) {
                    stck.pop();
                    first = 0;
                }

                stck.pop(topString);
            }
            stck.push( toStringFromChar(exp[i]));
        }

        i++;
    }

    string stackTop;

    if ( !stck.isEmpty() ) {
        stck.pop(stackTop);
        postfix += stackTop;
    }

    while ( !stck.isEmpty() ) {
        stck.pop(stackTop);
        postfix += stackTop;
    }

    return postfix;
}

string prefix2infix( const string exp ) {
    return NULL;
}

string prefix2postfix( const string exp ) {
    return NULL;
}

string postfix2infix( const string exp ) {
    return NULL;
}

string postfix2prefix( const string exp ) {
    return NULL;
}

double evaluateInfix( const string exp ) {
    return 0;
}

double evaluatePrefix( const string exp ) {
    return 0;
}

double evaluatePostfix( const string exp ) {
    double result;
    int i = 0;
    Stack stck;

    while ( exp[i] != '\0' ) {
        while ( exp[i] != ' ' && isOperand(exp[i]) ) {
            string currentNumber = "";
            int j = 0;
            int initialI = i;

            while ( exp[initialI + j] != ' ' ) {
                currentNumber += exp[initialI + j];
                j++;
                i++;
            }

            stck.push(currentNumber);
        }

        i++;
    }
    
    while ( !stck.isEmpty() ) {
        string top;
        stck.pop(top);
        cout << top << endl;
    }

    return result;
}
