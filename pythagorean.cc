#include <iostream>

using namespace std;

int main() {
    for ( int a = 0; a < 1000; a++ ) {
        int a2 = a*a;
        for(int b = a+1; b < 1000; b++) {
            int b2 = b*b;
            for ( int c = b+1; c < 1000; c++ ) {
                if ( a + b + c != 1000 ) continue;
                if ( a2 + b2 == c*c ) { 
                    cout << a*b*c << endl;
                    return 0;
                }
            }
        }
    }
}