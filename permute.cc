#include <iostream>
#include <vector>
using namespace std;

vector<string> permute( string str ) {
    
    vector<string> result;
    if ( str.size() == 1 ) {
        result.push_back( str );
        return result;
    }
    
    char ch = str[0];
    auto rest = permute( string(str, 1, str.size()-1) );
    for ( auto s: rest ) {
        for ( auto i = 0; i <= s.size(); i++ ) {
            string w(s);
            w.insert( i, 1, ch );
            result.push_back( w );
        }
    }
    
    return result;
}

int main() {
    
    auto res = permute( "abcd" );
    for( auto x: res ) cout << x << " ";
    cout << endl;
}