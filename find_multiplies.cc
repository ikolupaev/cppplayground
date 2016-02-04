//Find the sum of all the multiples of 3 or 5 below command line arg 

#include <vector> 
#include <iostream>
#include <cstdlib>

using namespace std;

void find_all_mults( vector<int> numbers, int limit, vector<int> &result ) {
    for ( int i = 0; i < limit; i++ ) {
        for( auto n: numbers ) {
            if( i % n == 0 ) {
                result.push_back( i );
                break;
            }
        }
    }
};

int main( int argc, char *argv[] ) {

    vector<int> numbers = {3,5};
    vector<int> result;

    auto limit = atoi( argv[1] );

    find_all_mults( numbers, limit, result );
    
    int sum = 0;
    for ( auto n: result ) {
      sum += n;
      cout << n << endl;  
    } 
    
    cout << "* " << sum << endl;
}