#include <iostream>
#include <thread>

using namespace std;

int lattice_paths_counter( int rows, int cols ) {

    if( rows == 0 || cols == 0 ) return 1;

    int rr = 0;
    rr += lattice_paths_counter( rows - 1, cols );
    rr += lattice_paths_counter( rows, cols - 1 );
        
    return rr;
} 

int main() {
    cout << lattice_paths_counter( 2, 2 ) << endl;
}