#include <iostream>

using namespace std;

int reverse(int n) {
    int result = 0;
    
    while( n > 0 ) {
        result = result * 10 + n % 10;
        n /= 10; 
    }
    
    return result;
}

int calc_max_palindrome( int min, int max ) {
    int max_p = 0;

    for( int a = min; a < max; a++ ) {
        for( int b = a; b < max; b++ ) {
            int ab = a*b;
            if( ab == reverse(ab) ) {
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