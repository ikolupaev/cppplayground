#include <iostream>

using namespace std;

bool is_palindrome( int num ) {
    string s( to_string(num) );
    
    for(int i = 0; i<s.size()/2; i++) 
        if( s[i] != s[s.size()-i-1] ) return false;

    return true;
}

int calc_max_palindrome( int min, int max ) {
    int max_p = 0;

    for( int a = min; a < max; a++ ) {
        for( int b = a; b < max; b++ ) {
            int ab = a*b;
            if( is_palindrome(ab) ) {
                max_p = std::max( ab, max_p );
            }
        }
    }

    return max_p;    
}

int main() {
    int palindrom = calc_max_palindrome( 100, 999 );
    cout << palindrom << endl;
}