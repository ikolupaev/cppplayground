#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_histogram( const vector<int> &n ) {
    
    auto minmax = minmax_element( n.begin(), n.end() );

    for ( int i = *minmax.first; i <= *minmax.second; i++ ) {
        int c = count( n.begin(), n.end(), i );
        cout << i << ":" << string( c, '*' ) << endl;
    }    
}

int main() {
    print_histogram( {1,1,2,2,3,3,3,3,5,5,5,9,9,9,4} );
}