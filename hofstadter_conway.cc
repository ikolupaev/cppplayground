#include <iostream>

using namespace std;

int hofstadter_conway( int n ) {
    if ( n < 3 ) return 1;
    int (*a)(int);
    a = hofstadter_conway; 
    int a1 = a(n-1);
    return a(a1)+a(n-a1);
}

int main() {
    for( int i = 1; i < 100; i++ ) {
        cout << hofstadter_conway( i ) << " " ;
    }
    
    cout << endl;
}