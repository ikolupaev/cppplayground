#include <iostream>

using namespace std;

string fizz_buzz( int n ) {

    string s("");
    
    if ( n % 3 == 0 ) s+= "Fizz"; 
    if ( n % 5 == 0 ) s += "Buzz";
    if ( s.empty() ) s = to_string( n );
    
    return s; 
}

int main() {
    for( int i = 0; i < 100; i++ ) {
        cout << fizz_buzz(i) << endl;
    }
}
