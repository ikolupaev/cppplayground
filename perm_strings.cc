#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool get_next_seq( vector<vector<string>> &v, vector<int> &seq ) {
    for ( int i = seq.size()-1; i >= 0; i-- ) {
        if ( seq[i] == v[i].size()-1 ) 
	        seq[i] = 0;
	    else { 
	        seq[i]++; 
	        return true;
	    }
    }
}

void print( vector<vector<string>> &v ) {
    vector<int> seq(v.size());
    for(  int i = 0; i < seq.size(); i++ ) seq[i] = 0;

    while ( true ) {
        for( int i = 0; i < v.size(); i++ )
            cout << v[i][seq[i]] << " ";
        
	    cout << endl;
	    
        if ( !get_next_seq( v, seq ) ) break; 
    }
}

int main() {
    vector<vector<string>> v { { "quick", "lazy"}, {"brown", "black", "grey"}, {"fox", "dog"} };
    print( v );	
}
