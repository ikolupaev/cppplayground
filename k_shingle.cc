#include <iostream>
#include <vector>

using namespace std;

void k_shingle( const string &s, size_t k, vector<string> &result ) {

    for( int i = 0; i <= s.size()-k; i++ ) {
        result.push_back( string( s, i, k ) );
    }
} 

int main() {
    vector<string> result;
    
    k_shingle( "123456789", 3, result );
    
    for ( auto x: result )
        cout << x << endl;
}