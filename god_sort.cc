#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std; 

void god_sort( vector<int> &v ) {
    srand(time(0));
    int counter = 0;
    while(1) {
        bool sorted = true;
        for( int i = 0; i < v.size()-1; i++ ) {
            if( v[i] > v[i+1] ) {
                sorted = false;
                break;
            }
        }
        
        if( sorted ) break;
        
        int i1 = rand() * v.size() / RAND_MAX;
        int i2 = rand() * v.size() / RAND_MAX;
        
        cout << "swaping #" << ++counter << " " << i1 << " " << i2 << endl; 
        swap( v[i1], v[i2] );
    }    
}

int main( int argc, const char* argv[] )
{
    vector<int> v;
    if( argc > 1 ) {
        int max = atoi( argv[1] );
        for( int i = 0; i < max; i++ )
        {
            v.push_back( max - i );
        }
    }
    else
    {
        v = {5,4,2,3,1};
    }

    god_sort( v );
    for( int &i : v ) cout << i << endl;
} 