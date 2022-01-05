// Yağız Can Aslan 22001943

#include <string>
#include <sstream>
#include "AlgebraicExpression.h"
#include "Stack.h"
using namespace std;

string trimmer( string s ) {
    int i = 0;
    string result;

    while ( s[i] == ' ' ) {
        i++;
    }

    while ( s[i] != '\0' ) {
        if ( s[i] != ' ' ) {
            if ( isOperator(s[i]) && isOperand(s[i - 1]) && s[i - 1] != ' ' ) {
                result = result + " ";
            }
            else if ( isOperand(s[i]) && isOperator(s[i - 1]) && s[i - 1] != ' ' ) {
                result = result + " ";
            }
            else if ( isOperator(s[i]) && isOperator(s[i - 1]) && s[i - 1] != ' ' ) {
                result = result + " ";
            }

            result = result + s[i];
        }
        else {
            result = result + " ";
            while ( s[i] == ' ' ) {
                i++;
            }

            i--;
        }

        i++;
    }

    return result;
}

double toDoubleFromString( string a ) {
    double result;
    stringstream stream;

    stream << a;
    stream >> result;

    return result;
}

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

int precedenceWithParanthesis( const char a ) {
    switch (a)
    {
    case '/':
        return 2;
        break;
    case '*':
        return 2;
        break;
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '(':
        return 0;
        break;
    case ')':
        return 0;
        break;
    default:
        return -1;
        break;
    }
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
    string result;
    result = infix2postfix(exp);
    result = postfix2prefix(result);
    return result;
}

string infix2postfix( const string exp ) {
    Stack stck;
    string postfix = "";
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

    return trimmer(postfix);
}

string prefix2infix( const string exp ) {
    Stack stck;
    string infix = "";
    int i = 0;
    int length = exp.length();
    int index = length - 1;

    while ( i < length ) {
        while ( exp[index - i] != ' ' && isOperand(exp[index - i]) ) {
            string currentNumber = "";

            while ( exp[index - i] != ' ' ) { // +[ ]12
                currentNumber = exp[index - i] + currentNumber;
                i++;   
            }

            stck.push(currentNumber);
        }

        if ( isOperator(exp[index - i]) ) {
            string firstString = "";
            stck.pop(firstString);

            string secondString = "";
            stck.pop(secondString);

            string resultString;
            switch (exp[index - i])
            {
            case '+':
                resultString = "( " + firstString + " + " + secondString + " )";
                break;
            case '-':
                resultString = "( " + firstString + " - " + secondString + " )";
                break;
            case '/':
                resultString = "( " + firstString + " / " + secondString + " )";
                break;
            case '*':
                resultString = "( " + firstString + " * " + secondString + " )";
                break;
            }
            stck.push( resultString);
        }

        i++;
    }

    stck.pop(infix);
    return infix;
}

string prefix2postfix( const string exp ) {
    string result;
    result = prefix2infix(exp);
    result = infix2postfix(result);
    return result;
}

string postfix2infix( const string exp ) {
    string result;
    result = postfix2prefix(exp);
    result = prefix2infix(result);
    return result;
}

string postfix2prefix( const string exp ) {
    string result = "";
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
        
        if ( isOperator(exp[i]) ) {
            string firstString = "";
            stck.pop(firstString);

            string secondString = "";
            stck.pop(secondString);

            string resultString;
            switch (exp[i])
            {
            case '+':
                resultString = "+ " + secondString + " " + firstString;
                break;
            case '-':
                resultString = "- " + secondString + " " + firstString;
                break;
            case '/':
                resultString = "/ " + secondString + " " + firstString;
                break;
            case '*':
                resultString = "* " + secondString + " " + firstString;
                break;
            }
            stck.push( resultString);
        }

        i++;
    }

    stck.pop(result);
    return result;
}

double evaluateInfix( const string exp ) {
    string eval;
    eval = infix2postfix( exp);
    return evaluatePostfix( eval);
}

double evaluatePrefix( const string exp ) {
    string eval;
    eval = prefix2postfix( exp);
    return evaluatePostfix( eval);
}

double evaluatePostfix( const string exp ) {
    double result;
    int i = 0;
    Stack stck;
    //string expression = trimmer(exp);
    string expression = exp;

    while ( expression[i] != '\0' ) {
        while ( expression[i] != ' ' && isOperand(expression[i]) ) {
            string currentNumber = "";
            int j = 0;
            int initialI = i;

            while ( expression[initialI + j] != ' ' ) {
                currentNumber += expression[initialI + j];
                j++;
                i++;
            }

            stck.push(currentNumber);
        }
        
        if ( isOperator(expression[i]) ) {
            double firstValue;
            string firstString;
            stck.pop(firstString);
            firstValue = toDoubleFromString(firstString);

            double secondValue;
            string secondString;
            stck.pop(secondString);
            secondValue = toDoubleFromString(secondString);

            double calculation;
            string resultString;
            ostringstream stringStream;

            switch (expression[i])
            {
            case '+':
                calculation = secondValue + firstValue;
                stringStream << calculation;
                resultString = stringStream.str();

                stck.push( resultString );
                break;
            case '-':
                calculation = secondValue - firstValue;
                stringStream << calculation;
                resultString = stringStream.str();

                stck.push( resultString );
                break;
            case '/':
                calculation = secondValue / firstValue;
                stringStream << calculation;
                resultString = stringStream.str();

                stck.push( resultString );
                break;
            case '*':
                calculation = secondValue * firstValue;
                stringStream << calculation;
                resultString = stringStream.str();

                stck.push( resultString );
                break;
            }
        }

        i++;
    }

    string resultString;
    stck.pop(resultString);
    result = toDoubleFromString(resultString);
    return result;
}
