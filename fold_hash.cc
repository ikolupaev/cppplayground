#include <string>
#include <iostream>

using namespace std;

uint32_t calc_fold_hash( string s ) {
    while ( s.size() % 4 != 0 )
        s.append( "#" );
    
    uint32_t hash = 0;
    for ( int i = 0; i < s.size(); i+= 4 ) {
        hash += s[i];
        hash += s[i+1] << 8;
        hash += s[i+2] << 16;
        hash += s[i+3] << 24;
    }
    
    return hash;
}

int main( int argc, char *argv[] ) {
    cout << calc_fold_hash( argv[1] ) << endl;
}