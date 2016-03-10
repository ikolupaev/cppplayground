#include "sum.h"
#include <iostream>

using namespace std;

string mult( string a, string b ) {
    vector<string> accum;
    
    reverse( a.begin(), a.end() );
    reverse( b.begin(), b.end() );
    
    for( int i = 0; i < a.size(); i++ ) {
        int aa = a[i] - '0';
        for( int j = 0; j < b.size(); j++ ) {
            int bb = b[j] - '0';
            
            int pp = aa * bb;
            string p = to_string( pp );
            p.append(j+i, '0');
            accum.push_back(p);
        }
    }
    
    return sum_str::sum( accum );
}

int main() {
    string a("1");
    for( int i = 2; i <= 100; i++ ) {
        a = mult( a, to_string(i) );        
    }

    cout << a << endl;
    
    int accum = 0;
    for( char ch:a )
        accum += ch - '0';
        
    cout << "sum of digits: " << accum << endl;
}