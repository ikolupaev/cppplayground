#include <iostream>

using namespace std;

int main() {
    int accum = 1;
    int n = 1;
    while( true ) {
        int divisors = 0;
        for ( int i = 1; i<=accum; i++ ) {
            if ( accum % i == 0 )  divisors++;
        }
        if ( divisors >= 500 ) {
            cout << accum << endl;
            return 0;
        }
        n++;
        accum += n;
    }
}
