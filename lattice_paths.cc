#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

using namespace std;

void lattice_paths_counter( int r, int c, int rows, int cols, uint64_t &result ) {

    if( r == rows && c == cols ) result += 1;

    if( r < rows )
        lattice_paths_counter( r+1, c, rows, cols, result );

    if( c < cols )
        lattice_paths_counter( r, c+1, rows, cols, result );
} 

int main() {
    vector<uint64_t> result = {0,0};

    int rows = 10;
    int columns = rows;
    
    vector<thread*> tt;
    
    tt.push_back( new thread( lattice_paths_counter, 1, 0, rows, columns, ref(result[0]) ) );
    tt.push_back( new thread( lattice_paths_counter, 0, 1, rows, columns, ref(result[1]) ) );

    for( thread *t : tt ) {
        t->join();
        delete t;
    }

    cout << accumulate( result.begin(), result.end(), 0 ) << endl;
}