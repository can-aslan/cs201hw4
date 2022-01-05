// Yağız Can Aslan 22001943

#include <iostream>
#include <string>
#include "AlgebraicExpression.h"
using namespace std;

int main() {
    cout << "Test started." << endl;
    cout << endl;

    cout << "----------------------------------------------------------" << endl;
    cout << "Testing INFIX to PREFIX..." << endl;
    cout << "Testing: " << "( 25 / 5 ) + ( ( 19 + 2 ) * 3 )" << endl;
    cout << "Result:   " << infix2prefix("( 25 / 5 ) + ( ( 19 + 2 ) * 3 )") << endl;
    cout << "Expected: " << "+ / 25 5 * + 19 2 3" << endl;
    cout << endl;

    cout << "Testing INFIX to POSTFIX..." << endl;
    cout << "Testing: " << "( 25 / 5 ) + ( ( 19 + 2 ) * 3 )" << endl;
    cout << "Result:   " << infix2postfix("( 25 / 5 ) + ( ( 19 + 2 ) * 3 )") << endl;
    cout << "Expected: " << "25 5 / 19 2 + 3 * +" << endl;
    cout << endl;

    cout << "Testing EVALUATE INFIX..." << endl;
    cout << "Testing: " << "( 25 / 5 ) + ( ( 19 + 2 ) * 3 )" << endl;
    cout << "Result:   " << evaluateInfix("( 25 / 5 ) + ( ( 19 + 2 ) * 3 )") << endl;
    cout << "Expected: " << "68" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;

    cout << "----------------------------------------------------------" << endl;
    cout << "Testing PREFIX to INFIX..." << endl;
    cout << "Testing: " << "+ 92 / * 16 8 4" << endl;
    cout << "Result:   " << prefix2infix("+ 92 / * 16 8 4") << endl;
    cout << "Expected: " << "( 92 + ( ( 16 * 8 ) / 4 ) )" << endl;
    cout << endl;

    cout << "Testing PREFIX to POSTFIX..." << endl;
    cout << "Testing: " << "+ 92 / * 16 8 4" << endl;
    cout << "Result:   " << prefix2postfix("+ 92 / * 16 8 4") << endl;
    cout << "Expected: " << "92 16 8 * 4 / +" << endl;
    cout << endl;

    cout << "Testing EVALUATE PREFIX..." << endl;
    cout << "Testing: " << "+ 92 / * 16 8 4" << endl;
    cout << "Result:   " << evaluatePrefix("+ 92 / * 16 8 4") << endl;
    cout << "Expected: " << "124" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;

    cout << "----------------------------------------------------------" << endl;
    cout << "Testing POSTFIX to INFIX..." << endl;
    cout << "Testing: " << "12 4 / 2 4 5 - + *" << endl;
    cout << "Result:   " << postfix2infix("12 4 / 2 4 5 - + *") << endl;
    cout << "Expected: " << "( ( 12 / 4 ) * ( 2 + ( 4 - 5 ) ) )" << endl;
    cout << endl;

    cout << "Testing POSTFIX to PREFIX..." << endl;
    cout << "Testing: " << "12 4 / 2 4 5 - + *" << endl;
    cout << "Result:   " << postfix2prefix("12 4 / 2 4 5 - + *") << endl;
    cout << "Expected: " << "* / 12 4 + 2 - 4 5" << endl;
    cout << endl;

    cout << "Testing EVALUATE POSTFIX..." << endl;
    cout << "Testing: " << "12 4 / 2 4 5 - + *" << endl;
    cout << "Result:   " << evaluatePostfix("12 4 / 2 4 5 - + *") << endl;
    cout << "Expected: " << "3" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;

    cout << "Test completed." << endl;
    return 0;
}