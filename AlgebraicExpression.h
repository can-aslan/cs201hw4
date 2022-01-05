// Yağız Can Aslan 22001943

#include <string>
using namespace std;

string infix2prefix( const string exp );
string infix2postfix( const string exp );
string prefix2infix( const string exp );
string prefix2postfix( const string exp );
string postfix2infix( const string exp );
string postfix2prefix( const string exp );
double evaluateInfix( const string exp );
double evaluatePrefix( const string exp );
double evaluatePostfix( const string exp );
bool precedence( const char a, const char b );
bool isOperator( const char a );
bool isOperand( const char a );
string toStringFromChar( char a );
char toCharFromString( string a );