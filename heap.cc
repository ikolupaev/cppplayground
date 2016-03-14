#include <vector>
#include <iostream>

using namespace std;

void max_heapify( vector<int> &v, int n ) {
    int l = n*2+1;
    int r = n*2+2;
    int max = n;
    if ( l < v.size() && v[l] > v[max] ) max = l;
    if ( r < v.size() && v[r] > v[max] ) max = r;
    if( max != n ) {
        swap( v[max], v[n] );
        max_heapify( v, max );
    }
}

int get_max( vector<int> &v ) {
    int max = v[0];
    v[0] = v.back();
    v.pop_back();
    max_heapify( v, 0 );
    return max;
}

void print_tree( vector<int> &v ) {
    cout << "---" << endl;
    for( auto it = v.begin(); it != v.end(); it++ ) {
    	cout << *it << endl;
    }
    cout << "---" << endl;
}

int main() {
    vector<int> v = {1,1,2,3,4,5,5,6,7,8,8};
    
    for( int i=v.size()/2-1; i>=0; i-- ) {
        max_heapify( v, i );
    }

    while( !v.empty() ) {
       cout << get_max( v ) << endl;
    }
}
