#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std; 

void god_sort( vector<int> &v ) {
    srand(time(0));
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
        
        cout << "swaping " << i1 << " " << i2 << endl; 
        swap( v[i1], v[i2] );
    }    
}

int main()
{
    vector<int> v = {4,2,3,1};
    god_sort( v );
    for( int &i : v ) cout << i << endl;
} 